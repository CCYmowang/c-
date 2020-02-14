//�ļ�ժҪ�������˱��ʽ�еļǺ�Token��������͡�
//17130130312 �ܳ���
//2019.6.18

#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <string>
using namespace std;

enum Token_value//���ʽ��������Ч�Ǻŵ�����
{
    END,        NUMBER,
    PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
    LP='(',     RP=')'
};

struct t_token
{
    Token_value tok_kind;//�Ǻŵ�����
    string tok_txt;//�Ǻŵ��ı�
    long tok_pos;//�Ǻ���ԭ���ʽ���е�λ��
    t_token() : tok_kind(END), tok_pos(-1) {}//�Ǻŵ�ȱʡ���캯��
    t_token(Token_value kind, const string& txt, long pos)//�Ǻŵķ�ȱʡ���캯��
         : tok_kind(kind), tok_txt(txt), tok_pos(pos)
    {}
    void clear()
    {
        tok_kind =END; tok_txt.clear(); tok_pos =-1;
    }
};
#endif // LEXER_H_INCLUDED
