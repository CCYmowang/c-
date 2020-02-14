//文件摘要：实现了解析器类型 CExprParser 和词法分析器 CExprLexer 的成员函数。
//17130130312 曹晨瑶
//2019.6.18

#include <iostream>
#include "Parser.hpp"
#include "ExprNode_d.hpp"
using namespace std;

//词法分析器部分
class CExprParser::CExprLexer
{
private:
    const char* mpText;// 被扫描的字符串起始地址
    const char* mpPos;// 当前扫描到的位置
    char lastChar;// 最近一次读到的字符

    bool ignoreChar(char c) const;//是否忽略某个字符
    bool getChar(char& outChar);//获取字符串中的下一个字符
    void backChar();//回退一个字符
    long tellg() const
    {
        return long(mpPos-mpText);
    }
public:
    CExprLexer(const char* exprText)//构造函数
        :mpText(exprText),mpPos(exprText),lastChar('\0')
    {}
    ~CExprLexer(){}
    void setSource(const char* exprText)//给词法分析器设定值
     {
         mpText = mpPos = exprText;
         lastChar = '\0';
     }
     t_token nextToken();//从给定字符串中获取下一个字符
};

bool CExprParser::CExprLexer::getChar(char& outChar)//获取字符串中的下一个字符};
{
    if(mpPos==NULL||*mpPos=='\0')//空串
    {
        lastChar='\0';
        return false;
    }
    lastChar = *mpPos;//记录本次读到的字符
    outChar  = lastChar;
     ++mpPos;
     return true;
}
void CExprParser::CExprLexer::backChar()//回退一个字符
 {
     if(NULL == mpPos || mpText == mpPos)//空串
         return;

     if( '\0' == lastChar ) // 若上次已经读了末尾标志则不再允许回退字符
         return;

     --mpPos;          // 回退一个字符
 }
bool CExprParser::CExprLexer::ignoreChar(const char c) const//是否忽略某个字符
{
    const char * ignore_chars = " \t\f\v";//应该忽略的字符
     for(const char* pc=ignore_chars; *pc != '\0'; ++pc)
     {
         if( c == *pc )
             return true;
     }
     return false;
}
t_token CExprParser::CExprLexer::nextToken()//从给定字符串中获取下一个字符
{
    t_token token;
    char ch='\0';
    do// 忽略除了换行符之外的 其他空白字符，如空格，制表符等
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
     case '\0': // 字符串读完
     case ';' : // 分号，表达式结束
     case '\n': // 换行符，表达式结束
     case '\r': // 回车符，表达式结束
         token.tok_pos = tellg();
         token.tok_txt = ch;
         token.tok_kind =END;
         return token;
     case '*':  case '/':  case '+':  case '-':
     case '(':  case ')'://加减乘除以及括号
         token.tok_pos = tellg();
         token.tok_txt = ch;
         token.tok_kind = Token_value(ch);
         return token;
     // 对数值的处理
     case '0': case '1': case '2': case '3': case '4':
     case '5': case '6': case '7': case '8': case '9':
     case '.':
         {
             bool hasDot = false; //一个数值中，小数点最多出现1次.
             if( ch == '.' ) hasDot = true;
             token.tok_pos = tellg();
             token.tok_txt = ch;
             while ( getChar(ch) )
             {
                 if( isdigit(ch) ) // 数字 字符
                     token.tok_txt += ch;
                 else if(ch == '.' && hasDot == false)//第一次出现小数点
                 {
                     token.tok_txt += ch; hasDot = true;
                 }
                 else
                     break;
             }
             // while 循环会多读一个字符，将该字符退回
             backChar();
         }
         token.tok_kind = NUMBER;
         return token;

     default:
         throw char_error(ch, tellg());// 其他情况则报告: 发现无效字符
     }
 }

//语法解析器部分
CExprParser::CExprParser() //构造函数
    :mLexer(NULL){}
CExprParser:: ~CExprParser()//析构函数
{
    if(mLexer!=NULL)
        delete mLexer;
}
Token_value CExprParser::get_token()//获取下一个记号
{
     curr_token = mLexer->nextToken();//获取下一个记号
     return curr_token.tok_kind;//返回其种类
 }

SyntaxTree* CExprParser::parse_expr(const char* exprText)//解析表达式并构造语法树
{
    if(NULL == mLexer)
         mLexer = new CExprLexer(exprText);
     else
         mLexer->setSource(exprText); // 准备词法分析器

     get_token();  //获取表达式中的第一个单词
     if ( END == curr_token.tok_kind )
     {
         return NULL; // 表达式为空
     }
     basic_node* root = expr(false, false);//解析得到表达式的根结点
     mLexer->setSource(NULL);
     if(NULL == root) // 空表达式，为空树
         return NULL;
     SyntaxTree *theTree =NULL;
     try
     {
         theTree = new SyntaxTree( root );
     }
     catch(...)
     {
         delete root;  // 销毁已得到的语法树，再重新抛出异常
         throw;  // re-throw the exception again
     }
     return theTree;
 }

basic_node* CExprParser::expr(bool get,bool afterLP)//识别二元加、减法，并构造对应的语法树
{
    basic_node* left=NULL;
    basic_node* right=NULL;
    left=term(get);//左子树的根结点
    for(;;)
    {
        struct t_token fatherToken = curr_token;//获取当前记号
        switch(curr_token.tok_kind)//判断当前记号的类型
        {
            case PLUS://加法
                right=term(true);//获取右操作数子树
                left = new CPlusNode(fatherToken,left,right);
                break;
            case MINUS://减法
                right=term(true);//获取右操作数子树
                left = new CMinusNode(fatherToken,left,right);
                break;
            case END://表达式结束
                return left;
            case RP://表达式右边是否存在多余的右括号
                if(afterLP)
                    return left;//表达式结束
                else
                {
                    delete left;
                    string msg="多余的右括弧[";
                    msg+=curr_token.tok_txt+"]";
                    throw Syntax_error(msg.c_str(),curr_token.tok_pos);
                }
                break;
            default://有无效字符，报错
                delete left;
                string msg="无效字符[";
                msg+=curr_token.tok_txt+"]";
                throw Syntax_error(msg.c_str(),curr_token.tok_pos);
        }
    }
    return left;
}
basic_node* CExprParser::term(bool get)//识别乘、除法，并构造对应的语法树
{
    basic_node* left;
    basic_node* right;
    left=prim(get);//左子树的根结点
    for(;;)
    {
        struct t_token fatherToken = curr_token;//获取当前记号
        switch(curr_token.tok_kind)//判断当前记号的类型
        {
            case MUL://乘法
                right=prim(true);//获取右操作数子树
                left = new CMulNode(fatherToken,left,right);
                break;
            case DIV://除法
                right=prim(true);//获取右操作数子树
                left = new CDivNode(fatherToken,left,right);
                break;
            default:
                return left;
        }
    }
    return left;
}
basic_node* CExprParser::prim(bool get) //识别一元加、减法，括号，数值，并构造对应的语法
{
    basic_node* left=NULL;
    if(get)
        get_token();
    switch(curr_token.tok_kind)
    {
        case NUMBER://数值
            {
                left=new CNumberNode(curr_token);
                get_token();
                return left;
            }
        case MINUS://一元减
            {
                struct t_token fatherToken = curr_token;
                basic_node* child=prim(true);
                left=new CUnaryMinusNode(fatherToken,child);//为区别于二元减，将一元减用符号‘！’来表示
                return left;
            }
        case PLUS://一元加
            {
                struct t_token fatherToken = curr_token;
                basic_node* child=prim(true);
                left=new CUnaryPlusNode(fatherToken,child);//为区别于二元减，将一元减用符号‘！’来表示
                return left;
            }
        case LP://左括号
            {
                left = expr(true,true);
                if(curr_token.tok_kind!=RP)//缺少右括号，报错
                {
                    throw Syntax_error("')' expected",curr_token.tok_pos);
                }
                get_token();
                return left;
            }
        default://无效单词，报错
            throw Syntax_error("primary expected",curr_token.tok_pos);
    }
    return NULL;
}
