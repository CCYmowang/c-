//�ļ�ժҪ�����ַ���ת��Ϊ����������ʮ���ơ��˽��ơ�ʮ������
//���ߣ�17130130312 �ܳ���
//2019.4.13
#include <iostream>
#include<string>

using namespace std;
int main(){
    int result;//���������
    string str;
    cin>>str;
    const char *p=str.c_str();//��������ַ�������ת��Ϊ����
    result=atoi(p);
    cout<<"result:"<<result<<endl;
    return 0;
}

