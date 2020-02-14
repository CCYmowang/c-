//�ļ�ժҪ��ʵ���˱��ʽ���� Expr �ĳ�Ա������
//17130130312 �ܳ���
//2018.6.18

#include <bits/stdc++.h>
#include "Expr.hpp"
#include "ExprNode.hpp"
#include "Parser.hpp"
using namespace std;

Expr::Expr() :mTree(NULL),mError(NULL) {}//���캯��
Expr::Expr(const char* strExpr) :mTree(NULL),mError(NULL)//���캯��
{
    setText(strExpr);
}
Expr::~Expr()//��������
{
    if(mTree!=NULL)
        delete mTree;
    if(mError!=NULL)
        delete mError;
}
void Expr::setText(const char* strExpr)//������д���ʽ�������ı�����֮����Ϊ�﷨��
{
    //���ԭ����Ϣ
    if(mTree!=NULL)
        delete mTree;
    if(mError!=NULL)
        delete mError;

    mTree=NULL;
    mError=NULL;
    mText.assign(strExpr);
    try
    {
        CExprParser theParser;//�ñ��ʽ���﷨����������
        mTree=theParser.parse_expr(mText.c_str());//�������ʽ�������﷨�������ظ����
    }
    catch(exprException& ex)//����Ϊ�﷨���Ĺ������׳�����
    {
        mError=ex.clone();
        throw;
    }
}

double Expr::eval()//������ʽ��ֵ
{
    if(mTree==NULL)
        return 0;
    return mTree->eval();
}

string Expr::prin_pre_fix() const//�������ʽ��ǰ׺ʽ
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generatePrefix(retValue);//���﷨����������ǰ׺ʽ
    return retValue;
}
string Expr::print_in_fix() const//�������ʽ����׺ʽ
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generateInfix(retValue);//���﷨������������׺ʽ
    return retValue;
}
string Expr::print_post_fix() const//�������ʽ�ĺ�׺ʽ
{
    if(mTree==NULL)
    {
        if(mError==NULL)
            return "<Empty expression>\n";
        else
            return "<Invalidate expression>\n";
    }

    string retValue;
    mTree->generatePostfix(retValue);//���﷨���������ɺ�׺ʽ
    return retValue;
}
void Expr::printTree(std::ostream& outDevice) const//���������ӡ�﷨��
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
     mTree->printTree(outDevice, 0); // ���﷨����ӡ�Լ�
     outDevice << "}\n";
}
