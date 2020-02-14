//文件摘要：将字符串转化为整数，包括十进制、八进制、十六进制
//作者；17130130312 曹晨瑶
//2019.4.13
#include <iostream>
#include<string>

using namespace std;
int main(){
    int result;//变量，结果
    string str;
    cin>>str;
    const char *p=str.c_str();//将输入的字符串类型转化为常量
    result=atoi(p);
    cout<<"result:"<<result<<endl;
    return 0;
}

