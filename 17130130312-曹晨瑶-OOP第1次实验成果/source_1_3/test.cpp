#include"test.h"
#include<iostream>
using namespace std;
void itoa(int n,char* str)
{
    if(n==-2147483648){//�쳣����
        //cout<<"";
        char *p="-2147483648";
        char *pp=str;
        while(*p!='\0')
        {
            *pp=*p;
            pp++;
            p++;
        }
        *pp='\0';
        //cout<<str;
        return ;
    }
    char *p=str;
    if(n<0)
    {
        n=0-n;
        *p='-';
        p++;
    }//������ת��Ϊ����
    int stack[50];//��ջ����
    int top=0;//ջ��ָ��
    while(n){//�м����
        stack[top]=n%10;
        n=n/10;
        top++;
    }
    top--;
    while(top!=-1){
        *p=stack[top]+'0';//ת��
        //cout<<*str;
        p++;
        top--;
    }
    *p='\0';
}

