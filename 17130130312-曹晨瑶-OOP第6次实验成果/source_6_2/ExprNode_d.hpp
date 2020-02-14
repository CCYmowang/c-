//文件摘要：定义了树结点类型 basic_node 的全部 派生类。
//17130130312 曹晨瑶
//2019.6.18
#ifndef EXPRNODE_DERIVED_H_INCLUDED
#define EXPRNODE_DERIVED_H_INCLUDED

#include <cstdlib>
#include "ExprNode.hpp"
#include "error.hpp"

//非叶子结点 对应的结点类型

class COpNode : public basic_node//语法树非叶子结点的类型
{
    public:
        virtual ~COpNode(){}//析构函数
    protected:
        COpNode(const t_token& token)//构造函数
            :basic_node(token) {}//初始化基类
};

//二元运算所对应的语法树结点类型

class CBinaryOpNode : public COpNode//所有二元运算对应的语法树结点之基类
{
    protected:
        basic_node *mLeftChild;//左孩子，第一个操作数的子树
        basic_node *mRightChild;//右孩子，第二个操作数的子树
        CBinaryOpNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
            :COpNode(token),mLeftChild(pLeft),mRightChild(pRight)
        {}//构造函数
    public:
        virtual ~CBinaryOpNode();//析构函数
        virtual void generatePostfix(string& retValue) const;// 产生子表达式的后缀式
        virtual void generatePrefix(string& retValue) const;// 产生子表达式的前缀式
        virtual void generateInfix(string& retValue) const;// 产生子表达式的中缀式，并添加括号
        virtual void printTree(ostream& outDevice,int deepth) const ;
};
//二元 加法 运算的语法树结点类型
class CPlusNode : public CBinaryOpNode
{
public:
    CPlusNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//构造函数
    virtual double eval() const//计算子表达式的值
    {
        return mLeftChild->eval()+mRightChild->eval();
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CPlusNode";
    }
};
//二元 减法 运算的语法树结点类型
class CMinusNode : public CBinaryOpNode
{
public:
    CMinusNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//构造函数
    virtual double eval() const//计算子表达式的值
    {
        return mLeftChild->eval()-mRightChild->eval();
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CMinusNode";
    }
};
//二元 乘法 运算的语法树结点类型
class CMulNode : public CBinaryOpNode
{
public:
    CMulNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {}//构造函数
    virtual double eval() const//计算子表达式的值
    {
        return mLeftChild->eval()*mRightChild->eval();
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CMulNode";
    }
};
//二元 除法 运算的语法树结点类型
class CDivNode : public CBinaryOpNode
{
public:
    CDivNode(const t_token& token,basic_node *pLeft,basic_node *pRight)
        :CBinaryOpNode(token,pLeft,pRight)
    {} //构造函数
    virtual double eval() const//计算子表达式的值
    {
        double r=mRightChild->eval();
        if(r>=-0.000001&&r<=0.000001)
            throw CDiv0(mRightChild->getPosition());
        return mLeftChild->eval()/r;
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CDivNode";
    }
};

//一元 运算所对应的语法树结点类型

class CUnaryOpNode : public COpNode//所有二元运算对应的语法树结点之基类
{
    protected:
        basic_node *mChild;//一元运算操作数的子树
        CUnaryOpNode(const t_token& token,basic_node *pChild)
            :COpNode(token),mChild(pChild)
        {}//构造函数
    public:
        virtual ~CUnaryOpNode();//析构函数
        virtual void generatePostfix(string& retValue) const;// 产生子表达式的后缀式
        virtual void generatePrefix(string& retValue) const;// 产生子表达式的前缀式
        virtual void generateInfix(string& retValue) const;// 产生子表达式的中缀式，并添加括号
        virtual void printTree(ostream& outDevice,int deepth) const ;
};
//一元 加法 运算的结点类型
class CUnaryPlusNode : public CUnaryOpNode
{
public:
    CUnaryPlusNode(const t_token& token,basic_node *pChild)
        :CUnaryOpNode(token,pChild)
    {}//构造函数
    virtual double eval() const//计算子表达式的值
    {
        return mChild->eval();
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CUnaryPlusNode";
    }
};
//一元 减法 运算的结点类型
class CUnaryMinusNode : public CUnaryOpNode
{
public:
    CUnaryMinusNode(const t_token& token,basic_node *pChild)
        :CUnaryOpNode(token,pChild)
    {}//构造函数
    virtual double eval() const//计算子表达式的值
    {
        return (-1)*mChild->eval();
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CUnaryMinusNode";
    }
};

//叶子结点 对应的语法树结点类型

class CLeafNode : public basic_node//叶子结点的基类
{
    protected:
        CLeafNode(const t_token& token) :basic_node(token){}//构造函数
};
//数值型操作数对应的语法树叶子结点类型
class CNumberNode : public CLeafNode
{
public:
    CNumberNode(const t_token& token)
        :CLeafNode(token)
    {}//构造函数
    virtual double eval() const//记号的数值
    {
        return atof(mToken.tok_txt.c_str());
    }
    virtual const char* typeName() const//输出结点所属类名
    {
        return "CNumberNode";
    }
};

#endif // EXPRNODE_DERIVED_H_INCLUDED
