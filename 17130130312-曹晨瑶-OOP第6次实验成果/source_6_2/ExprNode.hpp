//�ļ�ժҪ���������﷨������ SyntaxTree �ͽ��Ļ������� basic_node��
//17130130312 �ܳ���
//2018.6.18

#ifndef EXPRNODE_H_INCLUDED
#define EXPRNODE_H_INCLUDED

#include <iostream>
#include <string>
#include "token.hpp"
using namespace std;

class basic_node//�����࣬���ʽ�﷨���Ļ����������
{
    protected://������ɷ���
        t_token mToken;//���Ǻ�
        basic_node(const t_token& token)//���캯��
            :mToken(token){}
    public:
        virtual ~basic_node(){}//��������
        virtual double eval() const=0;//���麯��
        virtual void generatePostfix(string& retValue) const;// �������ʽ�ĺ�׺ʽ
        virtual void generatePrefix(string& retValue) const;// �������ʽ��ǰ׺ʽ
        virtual void generateInfix(string& retValue) const;// �������ʽ����׺ʽ�����������
        virtual void printTree(ostream& outDevice,int deepth) const ;//��ӡ�Ե�ǰ���Ϊ��������
        const string& getText() const//����д�ŵļǺŵ��ı�
        {
            return mToken.tok_txt;
        }
        Token_value getKind() const//����д�ŵļǺŵ�����
        {
            return mToken.tok_kind;
        }
        long getPosition() const//����д�ŵļǺ��ڱ��ʽ�ַ����е�λ��
        {
            return mToken.tok_pos;
        }
        virtual const char* typeName() const=0;//���麯������ȡ��ʾ��ǰ��������
};
//���ʽ���﷨������
class SyntaxTree
{
private:
    basic_node* mRootNode;//�﷨�������

public:
    SyntaxTree(basic_node* theRoot)//���캯��
        :mRootNode(theRoot) {}
    virtual ~SyntaxTree()//��������
    {
        if(NULL != mRootNode)
             delete mRootNode; // ��ݹ���������н��
    }
    void setRoot(basic_node* theRoot)//���ø����
    {
        if(mRootNode!=NULL)
            delete mRootNode;
        mRootNode=theRoot;
    }
    basic_node* getRoot() const//��ȡ�����
    {
        return mRootNode;
    }
    double eval() const// ���㣨�ӣ����ʽ��ֵ
    {
        return (mRootNode==NULL)?0:mRootNode->eval();
    }
    // �������ʽ�ĺ�׺ʽ
    void generatePostfix(string& retValue) const
    {
        if(mRootNode==NULL)
            return ;
        mRootNode->generatePostfix(retValue);
        if( retValue[retValue.length()-1] == ' ') //ȥ��ĩβ�Ķ���ո�
             retValue.erase(retValue.length()-1);
    }
    void generatePrefix(string & retValue) const    // �������ʽ��ǰ׺ʽ
     {
         if(NULL == mRootNode)
            return;
         mRootNode->generatePrefix(retValue);
         if( retValue[retValue.length()-1] == ' ') //ȥ��ĩβ�Ķ���ո�
             retValue.erase(retValue.length()-1);
     }
     void generateInfix(string & retValue) const // �������ʽ����׺ʽ�����������
     {
         if(NULL == mRootNode)
            return;
         mRootNode->generateInfix(retValue);
         if( retValue[retValue.length()-1] == ' ') //ȥ��ĩβ�Ķ���ո�
             retValue.erase(retValue.length()-1);
     }
     void printTree(ostream& outDevice, int deepth) const
     {
         if(NULL == mRootNode)
            return;
         mRootNode->printTree(outDevice, deepth);
     }

};

#endif // EXPRNODE_H_INCLUDED
