//�ļ�ժҪ�������˱��ʽ���� Expr��
//17130130312 �ܳ���
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
        string mText;//�������ʽ��ԭʼ�ı�
        SyntaxTree* mTree;//���ʽ���﷨��������
        exprException *mError;//���ʽ�д��ڵĴ�������
    public:
        Expr() ;//���캯��
        Expr(const char* strExpr) ;
        ~Expr();//��������
        void setText(const char* strExpr);//������д���ʽ�������ı�����֮����Ϊ�﷨��
        const string& getText() const//��ȡ���ʽ�������ı�
        {
            return mText;
        }
        double eval();//������ʽ��ֵ
        string prin_pre_fix() const;//�������ʽ��ǰ׺ʽ
        string print_in_fix() const;//�������ʽ����׺ʽ
        string print_post_fix() const;//�������ʽ�ĺ�׺ʽ
        void printTree(ostream& outDevice) const;//�����������ӡ�﷨��
        const exprException* getError() const//��ȡ���ʽ�д��ڵĴ�����Ϣ����
        {
            return mError;
        }
};


#endif // EXPR_H_INCLUDED
