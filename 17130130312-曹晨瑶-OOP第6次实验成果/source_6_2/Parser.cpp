//�ļ�ժҪ��ʵ���˽��������� CExprParser �ʹʷ������� CExprLexer �ĳ�Ա������
//17130130312 �ܳ���
//2019.6.18

#include <iostream>
#include "Parser.hpp"
#include "ExprNode_d.hpp"
using namespace std;

//�ʷ�����������
class CExprParser::CExprLexer
{
private:
    const char* mpText;// ��ɨ����ַ�����ʼ��ַ
    const char* mpPos;// ��ǰɨ�赽��λ��
    char lastChar;// ���һ�ζ������ַ�

    bool ignoreChar(char c) const;//�Ƿ����ĳ���ַ�
    bool getChar(char& outChar);//��ȡ�ַ����е���һ���ַ�
    void backChar();//����һ���ַ�
    long tellg() const
    {
        return long(mpPos-mpText);
    }
public:
    CExprLexer(const char* exprText)//���캯��
        :mpText(exprText),mpPos(exprText),lastChar('\0')
    {}
    ~CExprLexer(){}
    void setSource(const char* exprText)//���ʷ��������趨ֵ
     {
         mpText = mpPos = exprText;
         lastChar = '\0';
     }
     t_token nextToken();//�Ӹ����ַ����л�ȡ��һ���ַ�
};

bool CExprParser::CExprLexer::getChar(char& outChar)//��ȡ�ַ����е���һ���ַ�};
{
    if(mpPos==NULL||*mpPos=='\0')//�մ�
    {
        lastChar='\0';
        return false;
    }
    lastChar = *mpPos;//��¼���ζ������ַ�
    outChar  = lastChar;
     ++mpPos;
     return true;
}
void CExprParser::CExprLexer::backChar()//����һ���ַ�
 {
     if(NULL == mpPos || mpText == mpPos)//�մ�
         return;

     if( '\0' == lastChar ) // ���ϴ��Ѿ�����ĩβ��־������������ַ�
         return;

     --mpPos;          // ����һ���ַ�
 }
bool CExprParser::CExprLexer::ignoreChar(const char c) const//�Ƿ����ĳ���ַ�
{
    const char * ignore_chars = " \t\f\v";//Ӧ�ú��Ե��ַ�
     for(const char* pc=ignore_chars; *pc != '\0'; ++pc)
     {
         if( c == *pc )
             return true;
     }
     return false;
}
t_token CExprParser::CExprLexer::nextToken()//�Ӹ����ַ����л�ȡ��һ���ַ�
{
    t_token token;
    char ch='\0';
    do// ���Գ��˻��з�֮��� �����հ��ַ�����ո��Ʊ����
    {
        if(!getChar(ch))
         {
             token.tok_txt = ch;
             token.tok_pos = tellg();
             token.tok_kind = END;
             return token;
         }
    }while(ignoreChar(ch));
    switch (ch)
    {
     case '\0': // �ַ�������
     case ';' : // �ֺţ����ʽ����
     case '\n': // ���з������ʽ����
     case '\r': // �س��������ʽ����
         token.tok_pos = tellg();
         token.tok_txt = ch;
         token.tok_kind =END;
         return token;
     case '*':  case '/':  case '+':  case '-':
     case '(':  case ')'://�Ӽ��˳��Լ�����
         token.tok_pos = tellg();
         token.tok_txt = ch;
         token.tok_kind = Token_value(ch);
         return token;
     // ����ֵ�Ĵ���
     case '0': case '1': case '2': case '3': case '4':
     case '5': case '6': case '7': case '8': case '9':
     case '.':
         {
             bool hasDot = false; //һ����ֵ�У�С����������1��.
             if( ch == '.' ) hasDot = true;
             token.tok_pos = tellg();
             token.tok_txt = ch;
             while ( getChar(ch) )
             {
                 if( isdigit(ch) ) // ���� �ַ�
                     token.tok_txt += ch;
                 else if(ch == '.' && hasDot == false)//��һ�γ���С����
                 {
                     token.tok_txt += ch; hasDot = true;
                 }
                 else
                     break;
             }
             // while ѭ������һ���ַ��������ַ��˻�
             backChar();
         }
         token.tok_kind = NUMBER;
         return token;

     default:
         throw char_error(ch, tellg());// ��������򱨸�: ������Ч�ַ�
     }
 }

//�﷨����������
CExprParser::CExprParser() //���캯��
    :mLexer(NULL){}
CExprParser:: ~CExprParser()//��������
{
    if(mLexer!=NULL)
        delete mLexer;
}
Token_value CExprParser::get_token()//��ȡ��һ���Ǻ�
{
     curr_token = mLexer->nextToken();//��ȡ��һ���Ǻ�
     return curr_token.tok_kind;//����������
 }

SyntaxTree* CExprParser::parse_expr(const char* exprText)//�������ʽ�������﷨��
{
    if(NULL == mLexer)
         mLexer = new CExprLexer(exprText);
     else
         mLexer->setSource(exprText); // ׼���ʷ�������

     get_token();  //��ȡ���ʽ�еĵ�һ������
     if ( END == curr_token.tok_kind )
     {
         return NULL; // ���ʽΪ��
     }
     basic_node* root = expr(false, false);//�����õ����ʽ�ĸ����
     mLexer->setSource(NULL);
     if(NULL == root) // �ձ��ʽ��Ϊ����
         return NULL;
     SyntaxTree *theTree =NULL;
     try
     {
         theTree = new SyntaxTree( root );
     }
     catch(...)
     {
         delete root;  // �����ѵõ����﷨�����������׳��쳣
         throw;  // re-throw the exception again
     }
     return theTree;
 }

basic_node* CExprParser::expr(bool get,bool afterLP)//ʶ���Ԫ�ӡ��������������Ӧ���﷨��
{
    basic_node* left=NULL;
    basic_node* right=NULL;
    left=term(get);//�������ĸ����
    for(;;)
    {
        struct t_token fatherToken = curr_token;//��ȡ��ǰ�Ǻ�
        switch(curr_token.tok_kind)//�жϵ�ǰ�Ǻŵ�����
        {
            case PLUS://�ӷ�
                right=term(true);//��ȡ�Ҳ���������
                left = new CPlusNode(fatherToken,left,right);
                break;
            case MINUS://����
                right=term(true);//��ȡ�Ҳ���������
                left = new CMinusNode(fatherToken,left,right);
                break;
            case END://���ʽ����
                return left;
            case RP://���ʽ�ұ��Ƿ���ڶ����������
                if(afterLP)
                    return left;//���ʽ����
                else
                {
                    delete left;
                    string msg="�����������[";
                    msg+=curr_token.tok_txt+"]";
                    throw Syntax_error(msg.c_str(),curr_token.tok_pos);
                }
                break;
            default://����Ч�ַ�������
                delete left;
                string msg="��Ч�ַ�[";
                msg+=curr_token.tok_txt+"]";
                throw Syntax_error(msg.c_str(),curr_token.tok_pos);
        }
    }
    return left;
}
basic_node* CExprParser::term(bool get)//ʶ��ˡ��������������Ӧ���﷨��
{
    basic_node* left;
    basic_node* right;
    left=prim(get);//�������ĸ����
    for(;;)
    {
        struct t_token fatherToken = curr_token;//��ȡ��ǰ�Ǻ�
        switch(curr_token.tok_kind)//�жϵ�ǰ�Ǻŵ�����
        {
            case MUL://�˷�
                right=prim(true);//��ȡ�Ҳ���������
                left = new CMulNode(fatherToken,left,right);
                break;
            case DIV://����
                right=prim(true);//��ȡ�Ҳ���������
                left = new CDivNode(fatherToken,left,right);
                break;
            default:
                return left;
        }
    }
    return left;
}
basic_node* CExprParser::prim(bool get) //ʶ��һԪ�ӡ����������ţ���ֵ���������Ӧ���﷨
{
    basic_node* left=NULL;
    if(get)
        get_token();
    switch(curr_token.tok_kind)
    {
        case NUMBER://��ֵ
            {
                left=new CNumberNode(curr_token);
                get_token();
                return left;
            }
        case MINUS://һԪ��
            {
                struct t_token fatherToken = curr_token;
                basic_node* child=prim(true);
                left=new CUnaryMinusNode(fatherToken,child);//Ϊ�����ڶ�Ԫ������һԪ���÷��š���������ʾ
                return left;
            }
        case PLUS://һԪ��
            {
                struct t_token fatherToken = curr_token;
                basic_node* child=prim(true);
                left=new CUnaryPlusNode(fatherToken,child);//Ϊ�����ڶ�Ԫ������һԪ���÷��š���������ʾ
                return left;
            }
        case LP://������
            {
                left = expr(true,true);
                if(curr_token.tok_kind!=RP)//ȱ�������ţ�����
                {
                    throw Syntax_error("')' expected",curr_token.tok_pos);
                }
                get_token();
                return left;
            }
        default://��Ч���ʣ�����
            throw Syntax_error("primary expected",curr_token.tok_pos);
    }
    return NULL;
}
