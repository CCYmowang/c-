//文件摘要：测试函数
//17130130312 曹晨瑶
//2019.5.29
#include <iostream>
#include "function.hpp"

using namespace std;

int main()
{
    Date date1(1970,1,1);
    date1.add_day(31);
    cout<<"*****************"<<endl;
    Date date2(2019,2);
    date2.add_month(4);
    cout<<"*****************"<<endl;
    Date date3(10);
    date3.add_year(3);
    cout<<"*****************"<<endl;
    Date date4;

    return 0;
}
