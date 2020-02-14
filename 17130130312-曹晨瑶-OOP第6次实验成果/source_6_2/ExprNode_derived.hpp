//�ļ�ժҪ����������������� basic_node ��ȫ�� �����ࡣ
//17130130312 �ܳ���
//2019.6.18
#ifndef EXPRNODE_DERIVED_H_INCLUDED
#define EXPRNODE_DERIVED_H_INCLUDED

#include <cstdlib>
#include "ExprNode.hpp"
#include "error.hpp"

//��Ҷ�ӽ�� ��Ӧ�Ľ������

class COpNode : public basic_node//�﷨����Ҷ�ӽ�������
{
    public:
        virtual ~COpNode(){}//��������
    protected:
        COpNode(const t_token& token)//���캯��
            :basic_node(token) {}//��ʼ������
};

//��Ԫ��������Ӧ���﷨���������

class CBinaryOpNode : public COpNode//���ж�Ԫ�����Ӧ���﷨�����֮����
{
    protected:
        basic_node *mLeftChild;//���ӣ���һ��������������
        basic_node *mRightChild;//�Һ��ӣ��ڶ���������������
        CBinaryOpNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
            :COpNode(token),mLeftChild(pLeft),mRightChild(pRight)
        {}//���캯��
    public:
        virtual ~CBinaryOpNode();//��������
        virtual void generatePostfix(string& retValue) const;// �����ӱ��ʽ�ĺ�׺ʽ
        virtual void generatePrefix(string& retValue) const;// �����ӱ��ʽ��ǰ׺ʽ
        virtual void generateInfix(string& retValue) const;// �����ӱ��ʽ����׺ʽ�����������
        virtual void printTree(ostream& outDevice,int deepth) const ;
};
//��Ԫ �ӷ� ������﷨���������
class CPlusNode : public CBinaryOpNode
{
public:
    CPlusNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        return mLeftChild->eval()+mRightChild->eval();
    }
    virtual const char* typeName() const//��������������
    {
        return "CPlusNode";
    }
};
//��Ԫ ���� ������﷨���������
class CMinusNode : public CBinaryOpNode
{
public:
    CMinusNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        return mLeftChild->eval()-mRightChild->eval();
    }
    virtual const char* typeName() const//��������������
    {
        return "CMinusNode";
    }
};
//��Ԫ �˷� ������﷨���������
class CMulNode : public CBinaryOpNode
{
public:
    CMulNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        return mLeftChild->eval()*mRightChild->eval();
    }
    virtual const char* typeName() const//��������������
    {
        return "CMulNode";
    }
};
//��Ԫ ���� ������﷨���������
class CDivNode : public CBinaryOpNode
{
public:
    CDivNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {} //���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        double r=mRightChild->eval();
        if(r>=-0.000001&&r<=0.000001)
            throw CDiv0(mRightChild->getPosition());
        return mLeftChild->eval()/r;
    }
    virtual const char* typeName() const//��������������
    {
        return "CDivNode";
    }
};

//һԪ ��������Ӧ���﷨���������

class CUnaryOpNode : public COpNode//���ж�Ԫ�����Ӧ���﷨�����֮����
{
    protected:
        basic_node *mChild;//һԪ���������������
        CUnaryOpNode(const t_token& token,basic_node *pChild)
            :COpNode(token),mChild(pChild)
        {}//���캯��
    public:
        virtual ~CUnaryOpNode();//��������
        virtual void generatePostfix(string& retValue) const;// �����ӱ��ʽ�ĺ�׺ʽ
        virtual void generatePrefix(string& retValue) const;// �����ӱ��ʽ��ǰ׺ʽ
        virtual void generateInfix(string& retValue) const;// �����ӱ��ʽ����׺ʽ�����������
        virtual void printTree(ostream& outDevice,int deepth) const ;
};
//һԪ �ӷ� ����Ľ������
class CUnaryPlusNode : public CUnaryOpNode
{
public:
    CUnaryPlusNode(const t_token& token,basic_node *pChild)
        :CUnaryOpNode(token,pChild)
    {}//���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        return mChild->eval();
    }
    virtual const char* typeName() const//��������������
    {
        return "CUnaryPlusNode";
    }
};
//һԪ ���� ����Ľ������
class CUnaryMinusNode : public CUnaryOpNode
{
public:
    CUnaryMinusNode(const t_token& token,basic_node *pChild)
        :CUnaryOpNode(token,pChild)
    {}//���캯��
    virtual double eval() const//�����ӱ��ʽ��ֵ
    {
        return (-1)*mChild->eval();
    }
    virtual const char* typeName() const//��������������
    {
        return "CUnaryMinusNode";
    }
};

//Ҷ�ӽ�� ��Ӧ���﷨���������

class CLeafNode : public basic_node//Ҷ�ӽ��Ļ���
{
    protected:
        CLeafNode(const t_token& token) :basic_node(token){}//���캯��
};
//��ֵ�Ͳ�������Ӧ���﷨��Ҷ�ӽ������
class CNumberNode : public CLeafNode
{
public:
    CNumberNode(const t_token& token)
        :CLeafNode(token)
    {}//���캯��
    virtual double eval() const//�Ǻŵ���ֵ
    {
        return atof(mToken.tok_txt.c_str());
    }
    virtual const char* typeName() const//��������������
    {
        return "CNumberNode";
    }
};

#endif // EXPRNODE_DERIVED_H_INCLUDED
