//�ļ�ժҪ��ʵ���˶������Ľ������ Tode
//17130130312 �ܳ���
//2019.5.25
#include"Tnode.hpp"
#include<string>

using namespace std;

Tnode::Tnode(const char* str)
    : word(NULL == str ? "" : str), count(1),
      left(NULL), right(NULL)
    //��Ա��ʼ���б�
{
}

Tnode::Tnode(const string& str)
{
     word = str;  // �� word ��ֵ�� ��ʼ�Ŀմ� �޸�Ϊ str ��ͬ��ֵ
     count = 1;   // �� count ��ֵ�� ��ʼ�����ֵ �޸�Ϊ 1
     left = right = NULL;
}

Tnode::~Tnode()
{
   /*
     if(NULL != left )  // �ݹ���ͷ�������
         delete left ;  // call Tnode::~Tnode()

     if(NULL != right ) //�ݹ���ͷ�������
         delete right ; // call Tnode::~Tnode()
   */
}
