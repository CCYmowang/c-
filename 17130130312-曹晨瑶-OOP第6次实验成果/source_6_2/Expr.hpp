//文件摘要：定义了表达式类型 Expr。
//17130130312 曹晨瑶
//2018.6.18

#ifndef EXPR_H_INCLUDED
#define EXPR_H_INCLUDED

#include <bits/stdc++.h>
#include "error.hpp"
using namespace std;

class SyntaxTree;
class Expr
{
    private:
        string mText;//算术表达式的原始文本
        SyntaxTree* mTree;//表达式的语法树的树根
        exprException *mError;//表达式中存在的错误描述
    public:
        Expr() ;//构造函数
        Expr(const char* strExpr) ;
        ~Expr();//析构函数
        void setText(const char* strExpr);//重新填写表达式的完整文本并将之解析为语法树
        const string& getText() const//获取表达式的完整文本
        {
            return mText;
        }
        double eval();//计算表达式的值
        string prin_pre_fix() const;//产生表达式的前缀式
        string print_in_fix() const;//产生表达式的中缀式
        string print_post_fix() const;//产生表达式的后缀式
        void printTree(ostream& outDevice) const;//先序遍历，打印语法树
        const exprException* getError() const//获取表达式中存在的错误信息描述
        {
            return mError;
        }
};


#endif // EXPR_H_INCLUDED
