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
    /*����һ��1000���ȵ��ַ����������������������Σ�գ��˴�������*/
    char Buffer[1000];
    //Expression expression;
    cout<<"����һ�����ʽ��"<<ends;
    gets(Buffer);
    try
    {
        char* Stream=Buffer;
        Expression* exp=exp->GetExp(Stream);
        while(*Stream==' ')Stream++;
        if(*Stream)
        {
            delete exp;
            throw Exception(Stream,(char*)"���ֶ�����ַ�");
        }
        else
        {
            cout<<"�������:";
            exp->PrintDLR();
            cout<<"\n�������:";
            exp->PrintLDR();
            cout<<"\n�������:";
            exp->PrintLRD();
            cout<<'\n'<<exp->calculate()<<endl;
            delete exp;
        }
    }
    catch(Exception& e)
    {
        cout<<"��������"<<endl;
        cout<<"λ�ã�"<<e.Start<<endl;;
        cout<<"��Ϣ��"<<e.Error<<endl;
    }
    return 0;
}
