//文件摘要：将指定的的整数转化（十进制）字符串
//17130130312 曹晨瑶
//2019.4.13
#include<iostream>
#include<cstring>
#include"test.h"
using namespace std;
int main()
{
    int n;
    char str[20];
    cin>>n;
    itoa(n,str);
    cout<<str;
    return 0;
}

