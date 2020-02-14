#include"tool.hpp"
#include"Exception.hpp"
#include"Expression.hpp"
#include<iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    /*声明一个1000长度的字符串缓冲区，可能有溢出的危险，此处不考虑*/
    char Buffer[1000];
    //Expression expression;
    cout<<"输入一个表达式："<<ends;
    gets(Buffer);
    try
    {
        char* Stream=Buffer;
        Expression* exp=exp->GetExp(Stream);
        while(*Stream==' ')Stream++;
        if(*Stream)
        {
            delete exp;
            throw Exception(Stream,(char*)"发现多余的字符");
        }
        else
        {
            cout<<"先序遍历:";
            exp->PrintDLR();
            cout<<"\n中序遍历:";
            exp->PrintLDR();
            cout<<"\n后序遍历:";
            exp->PrintLRD();
            cout<<'\n'<<exp->calculate()<<endl;
            delete exp;
        }
    }
    catch(Exception& e)
    {
        cout<<"发生错误"<<endl;
        cout<<"位置："<<e.Start<<endl;;
        cout<<"信息："<<e.Error<<endl;
    }
    return 0;
}
