//文件摘要：定义了表达式中的记号Token的相关类型。
//17130130312 曹晨瑶
//2019.6.18

#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <string>
using namespace std;

enum Token_value//表达式中所有有效记号的种类
{
    END,        NUMBER,
    PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
    LP='(',     RP=')'
};

struct t_token
{
    Token_value tok_kind;//记号的种类
    string tok_txt;//记号的文本
    long tok_pos;//记号再原表达式串中的位置
    t_token() : tok_kind(END), tok_pos(-1) {}//记号的缺省构造函数
    t_token(Token_value kind, const string& txt, long pos)//记号的非缺省构造函数
         : tok_kind(kind), tok_txt(txt), tok_pos(pos)
    {}
    void clear()
    {
        tok_kind =END; tok_txt.clear(); tok_pos =-1;
    }
};
#endif // LEXER_H_INCLUDED
