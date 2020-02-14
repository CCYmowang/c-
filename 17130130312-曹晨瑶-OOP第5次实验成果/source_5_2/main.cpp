//文件摘要：测试函数
//17130130312 曹晨瑶
//2019.6.1

#include <iostream>
#include "Vec4.hpp"

using namespace std;

int main()
{
    Vec4 a, b;
    cin >> a;
    cin >> b;
    cout<<"结果为："<<endl;
    a += b;
    cout << a << endl;
    a = b + 1;
    cout << a << endl;
    a -= 2.0;
    cout << a << endl;
    a = b * 2;
    cout << a << endl;
    a = a * b;
    cout << a << endl;
    a /= b;
    cout << a << endl;
    return 0;
}
