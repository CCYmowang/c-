//文件摘要：定义了complex类的接口
//17130130312 曹晨瑶
//2019.6.1
#ifndef COMPLEX_CLASS_HPP
#define COMPLEX_CLASS_HPP

#include<iostream>

using namespace std;
class complex
{
    double re,im;
public:
    complex(double r=0,double i=0) : re(r),im(i) {}

    double real() const {return re;}
    double imag() const {return im;}
    void setter_real(double a){ re=a;}
    void setter_imag(double a){ im=a;}

    complex& operator+=(complex a);
    complex& operator+=(double a);
    complex& operator-=(complex a);
    complex& operator-=(double a);
    complex& operator*=(complex a);
    complex& operator*=(double a);
    complex& operator/=(complex a);
    complex& operator/=(double a);
    friend istream& operator>>(istream& is,complex& a);//输入
    friend ostream& operator<<(ostream& os,complex& a);//输出
};
//辅助函数
complex operator+(complex a,complex b);
complex operator+(complex a,double b);
complex operator+(double a,complex b);
complex operator-(complex a,complex b);
complex operator-(complex a,double b);
complex operator-(double a,complex b);
complex operator*(complex a,complex b);
complex operator*(complex a,double b);
complex operator*(double a,complex b);
complex operator/(complex a,complex b);
complex operator/(complex a,double b);
complex operator/(double a,complex b);

complex operator-(complex a);//一元负号
complex operator+(complex a);
bool operator==(complex a,complex b);
bool operator!=(complex a,complex b);

std::istream& operator>>(std::istream& input,complex& a);//输入
std::ostream& operator<<(std::ostream& output,complex& a);//输出



#endif // COMPLEX _CLASS_HPP
