//文件摘要：日期计算对外接口
//17130130312 曹晨瑶
//2019.5.29
#ifndef CLASS_DATE_HPP
#define CLASS_DATE_HPP
using namespace std;
class Date{
public:
    //缺省处理
    Date(int y,int m,int d);//日、月、年 初始化
    Date(int m, int d);//日、月、本年
    Date(int dd);//日、本年、本月
    Date();//本日本月本年

    //修改Date的函数
    void add_day(int n);//加n天
    void add_month(int n);//加n月
    void add_year(int n);//加n年
    void print_date();//日期输出
private:
    int days;//自1970年1月1日以来的天数
};

int isleapyear(int year);//判断是否是闰年
void days_to_date(int new_days,int* y,int* m,int* d);
int date_to_days(int y,int m,int d);

#endif // CLASS_DATE_HPP
