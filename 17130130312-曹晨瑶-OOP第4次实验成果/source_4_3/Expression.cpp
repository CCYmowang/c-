#include"Expression.hpp"
#include"Exception.hpp"
#include"tool.hpp"
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
Expression::Expression(double aNumber)
{
    IsNumber=true;
    Number=aNumber;
    Operator=0;
    Left=0;
    Right=0;
}

Expression::Expression(char aOperator , Expression* aLeft , Expression* aRight)
{
    IsNumber=false;
    Number=0;
    Operator=aOperator;
    Left=aLeft;
    Right=aRight;
}
void Expression::PrintDLR()
{//����������
    if(IsNumber)
    {
        cout<<Number;
    }
    else
    {
        cout<<Operator<<" ";
        Left->PrintDLR();
        cout<<" ";
        Right->PrintDLR();
    }
}
void Expression::PrintLDR()
{
    //�������
    if(IsNumber)
    {
        cout<<Number;
    }
    else
    {
        cout<<"(";
        Left->PrintLDR();
        cout<<Operator;
        Right->PrintLDR();
        cout<<")";
    }
}
void Expression::PrintLRD()
{
    //�������
    if(IsNumber)
    {
        cout<<Number;
    }
    else
    {
        Left->PrintLRD();
        cout<<" ";
        Right->PrintLRD();
        cout<<Operator;
    }
}
double Expression::calculate()
{
    if(IsNumber)
    {
        return Number;
    }
    else
    {
        switch (Operator){
            case '+':
                    return Left->calculate()+Right->calculate();
                    break;
            case '-':
                    return Left->calculate()-Right->calculate();
                    break;
            case '*':
                    return Left->calculate()*Right->calculate();
                    break;
            case '/':
                    if(Right->calculate()==0)
                    {
                            //
                            //Result.Start=RightRead;
                    }
                    else
                    {
                            return Left->calculate()/Right->calculate();
                    }
                    break;
            default:
                    break;
        }
    }
}
Expression::~Expression()
{
    if(Left)delete Left;
    if(Right)delete Right;
}
/*
���Stream�Ƿ�����
*/
Expression* Expression::GetNumber(char*& Stream)
{
    int Result=0;
    bool GotNumber=false;
    /*�������*/
    char* Read=Stream;
    /*���˿ո�*/
    while(*Read==' ')Read++;
    while(true)
    {
        /*����һ���ַ�����Readƫ��һ���ַ�*/
        char c=*Read;
        /*����ַ��Ƿ�Ϊ����*/
        if('0'<=c && c<='9')
        {
            /*�ѽ����ӽ�Result�����н�λ*/
            Result=Result*10+(c-'0');
            GotNumber=true;
            Read++;
        }
        else
        {
            break;
        }
    }
    if(GotNumber)
    {
        Stream=Read;
        return new Expression(Result);
    }
    else
    {
        throw Exception(Stream,(char*)"�˴���Ҫ���ʽ");;
    }
}
/*
���Stream�Ƿ�һ��Term
*/
Expression* Expression::GetTerm(char*& Stream)
{
    try
    {
        return GetNumber(Stream);
    }
    catch(Exception& e)
    {
        char* Read=Stream;
        /*���������*/
        if(Is(Read,(char*)"("))
        {
            /*�����ʽ*/
            Expression* Result=GetExp(Read);
            if(Is(Read,(char*)")"))
            {
                /*���ʹ�������Ž����򷵻ؽ��*/
                Stream=Read;
                return Result;
            }
            else
            {
                /*�����׳��쳣*/
                delete Result;
                throw Exception(Stream,(char*)"�˴���Ҫ������");
            }
        }
        else
        {
            throw e;
        }
    }
}
/*
���Stream�Ƿ�һ��Factor
*/
Expression* Expression::GetFactor(char*& Stream)
{
    /*���һ��Term*/
    char* Read=Stream;
    Expression* Result=GetTerm(Read);
    while(true)
    {
        /*���������Ƿ�˳���*/
        char Operator=0;
        if(Is(Read,(char*)"*"))
            Operator='*';
        else if(Is(Read,(char*)"/"))
            Operator='/';
        else
            break;
        if(Operator)
        {
            /*����ǳ˳���������һ��Term*/
            try
            {
                Result=new Expression(Operator,Result,GetTerm(Read));
            }
            catch(Exception& e)
            {
                /*�����쳣��ʱ������ɾ��Result�����ת���쳣*/
                delete Result;
                throw e;
            }
        }
    }
    Stream=Read;
    return Result;
}
/*
���Stream�Ƿ�һ��Exp
*/
Expression* Expression::GetExp(char*& Stream)
{
    /*���һ��Factor*/
    char* Read=Stream;
    Expression* Result=GetFactor(Read);
    while(true)
    {
        /*���������Ƿ�Ӽ���*/
        char Operator=0;
        if(Is(Read,(char*)"+"))
            Operator='+';
        else if(Is(Read,(char*)"-"))
            Operator='-';
        else
            break;
        if(Operator)
        {
            /*����ǼӼ���������һ��Factor*/
            try
            {
                Result=new Expression(Operator,Result,GetFactor(Read));
            }
            catch(Exception& e)
            {
                /*�����쳣��ʱ������ɾ��Result�����ת���쳣*/
                delete Result;
                throw e;
            }
        }
    }
    Stream=Read;
    return Result;
}







