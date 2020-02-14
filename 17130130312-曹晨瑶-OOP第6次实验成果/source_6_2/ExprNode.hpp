//文件摘要：定义了语法树类型 SyntaxTree 和结点的基本类型 basic_node。
//17130130312 曹晨瑶
//2018.6.18

#ifndef EXPRNODE_H_INCLUDED
#define EXPRNODE_H_INCLUDED

#include <iostream>
#include <string>
#include "token.hpp"
using namespace std;

class basic_node//抽象类，表达式语法树的基本结点类型
{
    protected://派生类可访问
        t_token mToken;//结点记号
        basic_node(const t_token& token)//构造函数
            :mToken(token){}
    public:
        virtual ~basic_node(){}//析构函数
        virtual double eval() const=0;//纯虚函数
        virtual void generatePostfix(string& retValue) const;// 产生表达式的后缀式
        virtual void generatePrefix(string& retValue) const;// 产生表达式的前缀式
        virtual void generateInfix(string& retValue) const;// 产生表达式的中缀式，并添加括号
        virtual void printTree(ostream& outDevice,int deepth) const ;//打印以当前结点为根的子树
        const string& getText() const//结点中存放的记号的文本
        {
            return mToken.tok_txt;
        }
        Token_value getKind() const//结点中存放的记号的种类
        {
            return mToken.tok_kind;
        }
        long getPosition() const//结点中存放的记号在表达式字符串中的位置
        {
            return mToken.tok_pos;
        }
        virtual const char* typeName() const=0;//纯虚函数。获取表示当前结点的类名
};
//表达式的语法树类型
class SyntaxTree
{
private:
    basic_node* mRootNode;//语法树根结点

public:
    SyntaxTree(basic_node* theRoot)//构造函数
        :mRootNode(theRoot) {}
    virtual ~SyntaxTree()//析构函数
    {
        if(NULL != mRootNode)
             delete mRootNode; // 会递归地销毁所有结点
    }
    void setRoot(basic_node* theRoot)//设置根结点
    {
        if(mRootNode!=NULL)
            delete mRootNode;
        mRootNode=theRoot;
    }
    basic_node* getRoot() const//获取根结点
    {
        return mRootNode;
    }
    double eval() const// 计算（子）表达式的值
    {
        return (mRootNode==NULL)?0:mRootNode->eval();
    }
    // 产生表达式的后缀式
    void generatePostfix(string& retValue) const
    {
        if(mRootNode==NULL)
            return ;
        mRootNode->generatePostfix(retValue);
        if( retValue[retValue.length()-1] == ' ') //去掉末尾的多余空格
             retValue.erase(retValue.length()-1);
    }
    void generatePrefix(string & retValue) const    // 产生表达式的前缀式
     {
         if(NULL == mRootNode)
            return;
         mRootNode->generatePrefix(retValue);
         if( retValue[retValue.length()-1] == ' ') //去掉末尾的多余空格
             retValue.erase(retValue.length()-1);
     }
     void generateInfix(string & retValue) const // 产生表达式的中缀式，并添加括弧
     {
         if(NULL == mRootNode)
            return;
         mRootNode->generateInfix(retValue);
         if( retValue[retValue.length()-1] == ' ') //去掉末尾的多余空格
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
