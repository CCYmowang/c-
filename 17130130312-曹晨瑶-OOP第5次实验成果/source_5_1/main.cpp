//�ļ�ժҪ��ʵ������complex
//17130130312 �ܳ���
//2019.6.1
#include <iostream>
#include "complex.hpp"
using namespace std;

int main()
{
    cout<<"*****��������*****"<<endl;
    complex a,b;
    cin>>a;
    cin>>b;
    complex r;
    cout<<"��Ϊ��";
    r=a+b;
    cout<< r <<endl;
    cout<<"��Ϊ��";
    r=a-b;
    cout<< r <<endl;
    cout<<"��Ϊ��";
    r=a*b;
    cout<< r <<endl;
    cout<<"��Ϊ��";
    r=a/b;
    cout<< r <<endl;
    return 0;


}
