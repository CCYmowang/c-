#include"test.h"
#include<iostream>
using namespace std;
int atoi(const char *str){
    int result=0;
    if(!((str[0]>='0'&&str[0]<='9')||str[0]=='+'||str[0]=='-'))
    {
            cout<<"�������";
            return 0;
    }//�쳣����
    bool flag=false;//��־�������������
    if(*str>='0'&&*str<='9' || *str=='+' ||*str=='-'){
    if(*str=='-'||*str=='+'){
        if(*str=='-')
            flag=true;
        str++;
        if(*str=='0'){
            str++;
            if(*str=='x'||*str=='X'){
                str++;
                while(*str!='\0'){
                    // 16����ת��Ϊ����������ֵ��
                    if(*str>='0'&&*str<='9')
                        result=result*16+*str-'0';
                    else if(*str>='a'&&*str<='f')
                        result=result*16+*str-'a'+10;
                    else if(*str>='A'&&*str<='F')
                        result=result*16+*str-'A'+10;
                        str++;
                }
            }
            else {//8����ת��Ϊ����������ֵ��
                while(*str!='\0'){
                    result=result*8+*str-'0';
                    str++;
                }
            }
         }
         else{//ʮ����ת��Ϊ����������ֵ��
             while(*str>='0' && *str<='9'){
                result=result*10+*str-'0';
                str++;
                if(result<0){
                result=2147483647;
                break;
                }
             }
         }
    }
    else{//û�������ŵ����
        if(*str=='0'){
            str++;
            if(*str=='x'||*str=='X'){
                str++;
                 while(*str!='\0'){
                    if(*str>='0'&&*str<='9')
                        result=result*16+*str-'0';
                    else if(*str>='a'&&*str<='f')
                        result=result*16+*str-'a'+10;
                    else if(*str>='A'&&*str<='F')
                        result=result*16+*str-'A'+10;
                    str++;
                }
            }
            else{
                while(*str!='\0'){
                    result=result*8+*str-'0';
                    str++;
                }
            }

         }
         else{
             while(*str>='0' && *str<='9'){
                result=result*10+*str-'0';
                str++;
                if(result<0){
                result=2147483647;
                break;
                }
             }
         }

    }
    return result*(flag?-1:1);//��ת����ľ���ֵ���Ϸ���
    }
}

