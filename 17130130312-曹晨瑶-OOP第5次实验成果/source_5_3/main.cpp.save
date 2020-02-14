//文件摘要：测试函数
//17130130312 曹晨瑶
//2019.6.1

#include <iostream>
#include"ptr.hpp"
#include<exception>
#include<cstdlib>


using namespace std;

struct error
{//异常报告数
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

    try//数组访问越界测试
    {
        //ta--;
        if( &(*TV)-&v[0]<0 || &(*TV)-&v[0]>200 ) throw error(1);
        //发现越界，抛出错误
    }
    catch(error)
    {
        cerr<<"error!"<<endl;
        //捕获错误，停止程序
        exit(1);
    }

    TV++;
    cout << TV->m << endl;
    TH = TV ++;
    cout << (*TH).m << endl;
    cout << TV->m << endl;

    return 0;
}
