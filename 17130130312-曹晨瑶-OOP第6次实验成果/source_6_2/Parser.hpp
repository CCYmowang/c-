//文件摘要：定义了表达式的解析器类型 class CexprParser。
//17130130312 曹晨瑶
//2019.6.18

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>
#include <string>
#include "token.hpp"
using namespace std;

class basic_node;
class SyntaxTree;

class CExprParser//语法分析器
{
    private:
        t_token  curr_token; // 当前的记号对象
        class CExprLexer;//声明该类
        CExprLexer* mLexer;//词法分析器对象
        Token_value get_token();//获取下一个记号
        basic_node* expr(bool get,bool afterLP);//识别二元加、减法，并构造对应的语法树
        basic_node* term(bool get);//识别乘、除法，并构造对应的语法树
        basic_node* prim(bool get);//识别一元加、减法，括号，数值，并构造对应的语法树
    public:
        CExprParser();//构造函数
        virtual ~CExprParser();//析构函数
        SyntaxTree* parse_expr(const char* exprText);//解析表达式并构造语法树

};

#endif // PARSER_H_INCLUDED
