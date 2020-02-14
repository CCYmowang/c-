//�ļ�ժҪ�������˱��ʽ�Ľ��������� class CexprParser��
//17130130312 �ܳ���
//2019.6.18

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>
#include <string>
#include "token.hpp"
using namespace std;

class basic_node;
class SyntaxTree;

class CExprParser//�﷨������
{
    private:
        t_token  curr_token; // ��ǰ�ļǺŶ���
        class CExprLexer;//��������
        CExprLexer* mLexer;//�ʷ�����������
        Token_value get_token();//��ȡ��һ���Ǻ�
        basic_node* expr(bool get,bool afterLP);//ʶ���Ԫ�ӡ��������������Ӧ���﷨��
        basic_node* term(bool get);//ʶ��ˡ��������������Ӧ���﷨��
        basic_node* prim(bool get);//ʶ��һԪ�ӡ����������ţ���ֵ���������Ӧ���﷨��
    public:
        CExprParser();//���캯��
        virtual ~CExprParser();//��������
        SyntaxTree* parse_expr(const char* exprText);//�������ʽ�������﷨��

};

#endif // PARSER_H_INCLUDED
