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
{//先序遍历输出
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
    //中序遍历
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
    //后序遍历
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
检查Stream是否数字
*/
Expression* Expression::GetNumber(char*& Stream)
{
    int Result=0;
    bool GotNumber=false;
    /*保存参数*/
    char* Read=Stream;
    /*过滤空格*/
    while(*Read==' ')Read++;
    while(true)
    {
        /*读入一个字符并将Read偏移一个字符*/
        char c=*Read;
        /*检查字符是否为数字*/
        if('0'<=c && c<='9')
        {
            /*把结果添加进Result，进行进位*/
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
        throw Exception(Stream,(char*)"此处需要表达式");;
    }
}
/*
检查Stream是否一个Term
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
        /*检查左括号*/
        if(Is(Read,(char*)"("))
        {
            /*检查表达式*/
            Expression* Result=GetExp(Read);
            if(Is(Read,(char*)")"))
            {
                /*如果使用右括号结束则返回结果*/
                Stream=Read;
                return Result;
            }
            else
            {
                /*否则抛出异常*/
                delete Result;
                throw Exception(Stream,(char*)"此处需要右括号");
            }
        }
        else
        {
            throw e;
        }
    }
}
/*
检查Stream是否一个Factor
*/
Expression* Expression::GetFactor(char*& Stream)
{
    /*获得一个Term*/
    char* Read=Stream;
    Expression* Result=GetTerm(Read);
    while(true)
    {
        /*检查接下来是否乘除号*/
        char Operator=0;
        if(Is(Read,(char*)"*"))
            Operator='*';
        else if(Is(Read,(char*)"/"))
            Operator='/';
        else
            break;
        if(Operator)
        {
            /*如果是乘除号则获得下一个Term*/
            try
            {
                Result=new Expression(Operator,Result,GetTerm(Read));
            }
            catch(Exception& e)
            {
                /*发生异常的时候，首先删除Result，其次转发异常*/
                delete Result;
                throw e;
            }
        }
    }
    Stream=Read;
    return Result;
}
/*
检查Stream是否一个Exp
*/
Expression* Expression::GetExp(char*& Stream)
{
    /*获得一个Factor*/
    char* Read=Stream;
    Expression* Result=GetFactor(Read);
    while(true)
    {
        /*检查接下来是否加减号*/
        char Operator=0;
        if(Is(Read,(char*)"+"))
            Operator='+';
        else if(Is(Read,(char*)"-"))
            Operator='-';
        else
            break;
        if(Operator)
        {
            /*如果是加减号则获得下一个Factor*/
            try
            {
                Result=new Expression(Operator,Result,GetFactor(Read));
            }
            catch(Exception& e)
            {
                /*发生异常的时候，首先删除Result，其次转发异常*/
                delete Result;
                throw e;
            }
        }
    }
    Stream=Read;
    return Result;
}







