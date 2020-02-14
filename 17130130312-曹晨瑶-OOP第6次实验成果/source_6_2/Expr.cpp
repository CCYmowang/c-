//文件摘要：实现了表达式类型 Expr 的成员函数。
//17130130312 曹晨瑶
//2018.6.18

#include <bits/stdc++.h>
#include "Expr.hpp"
#include "ExprNode.hpp"
#include "Parser.hpp"
using namespace std;

Expr::Expr() :mTree(NULL),mError(NULL) {}//构造函数
Expr::Expr(const char* strExpr) :mTree(NULL),mError(NULL)//构造函数
{
    setText(strExpr);
}
Expr::~Expr()//析构函数
{
    if(mTree!=NULL)
        delete mTree;
    if(mError!=NULL)
        delete mError;
}
void Expr::setText(const char* strExpr)//重新填写表达式的完整文本并将之解析为语法树
{
    //清空原有信息
    if(mTree!=NULL)
        delete mTree;
    if(mError!=NULL)
        delete mError;

    mTree=NULL;
    mError=NULL;
    mText.assign(strExpr);
    try
    {
        CExprParser theParser;//该表达式的语法分析器对象
        mTree=theParser.parse_expr(mText.c_str());//解析表达式，构造语法树并返回根结点
    }
    catch(exprException& ex)//解析为语法树的过程中抛出错误
    {
        mError=ex.clone();
        throw;
    }
}

double Expr::eval()//计算表达式的值
{
    if(mTree==NULL)
        return 0;
    return mTree->eval();
}

string Expr::prin_pre_fix() const//产生表达式的前缀式
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generatePrefix(retValue);//由语法树对象生成前缀式
    return retValue;
}
string Expr::print_in_fix() const//产生表达式的中缀式
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generateInfix(retValue);//由语法树对象生成中缀式
    return retValue;
}
string Expr::print_post_fix() const//产生表达式的后缀式
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generatePostfix(retValue);//由语法树对象生成后缀式
    return retValue;
}
void Expr::printTree(std::ostream& outDevice) const//先序遍历打印语法树
{
    outDevice << "Syntax tree for expression [" << mText << "]:\n";
     if(NULL == mTree)
     {
         if(NULL == mError)
             outDevice << "NULL Tree<expression is empty>\n";
         else
             outDevice << "NULL Tree<expression has error: "
                       << mError->what() << ">\n";
         return;
     }
     outDevice << "{\n";
     mTree->printTree(outDevice, 0); // 由语法树打印自己
     outDevice << "}\n";
}
