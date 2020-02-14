#include"test.h"
#include<iostream>
using namespace std;
void itoa(int n,char* str)
{
    if(n==-2147483648){//异常处理
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
    }//将负数转化为整数
    int stack[50];//堆栈数组
    int top=0;//栈顶指针
    while(n){//中间过程
        stack[top]=n%10;
        n=n/10;
        top++;
    }
    top--;
    while(top!=-1){
        *p=stack[top]+'0';//转化
        //cout<<*str;
        p++;
        top--;
    }
    *p='\0';
}

