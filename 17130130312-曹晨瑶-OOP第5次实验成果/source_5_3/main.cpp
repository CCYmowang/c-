//�ļ�ժҪ�����Ժ���
//17130130312 �ܳ���
//2019.6.1

#include <iostream>
#include"ptr.hpp"
#include<exception>
#include<cstdlib>


using namespace std;

struct error
{//�쳣������
    int i;
    error(int ii){ i=ii; }
};

int main()
{
    T v[200],h[200];
    for(int i=0;i<200;i++)
    {
        v[i].m = i;
    }
    Ptr_to_T TV(&v[0],v,200);
    Ptr_to_T TH(&h[0],h,200);

    try//�������Խ�����
    {
        //ta--;
        if( &(*TV)-&v[0]<0 || &(*TV)-&v[0]>200 ) throw error(1);
        //����Խ�磬�׳�����
    }
    catch(error)
    {
        cerr<<"error!"<<endl;
        //�������ֹͣ����
        exit(1);
    }

    TV++;
    cout << TV->m << endl;
    TH = TV ++;
    cout << (*TH).m << endl;
    cout << TV->m << endl;

    return 0;
}
