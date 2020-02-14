//文件摘要：实现了类complex
//17130130312 曹晨瑶
//2019.6.1

#include <iostream>
#include <string>
#include<cstdlib>
#include "complex.hpp"
using namespace std;

complex& complex::operator+=(complex a)
{
    re+=a.re;
    im+=a.im;
    return *this;
}

complex& complex::operator+=(double a)
{
    re=re+a;
    return *this;
}
complex& complex::operator-=(complex a)
{
    re-=a.re;
    im-=a.im;
    return *this;

}
complex& complex::operator-=(double a)
{
    re=re-a;
    return *this;
}
complex& complex::operator*=(complex a)
{
    double r=re;
    re=re*a.re-im*a.im;
    im=r*a.im+a.re*im;
    return *this;
}
complex& complex::operator*=(double a)
{
    re=re*a;
    return *this;

}
complex& complex::operator/=(complex a)
{
    double r=re;
    re=(re*a.re+im*a.im)/(a.re*a.re+a.im*a.im);
    im=(im*a.re-r*a.im)/(a.re*a.re+a.im*a.im);
    return *this;
}
complex& complex::operator/=(double a)
{
    re=re/a;
    return *this;
}
//辅助函数
complex operator+(complex a,complex b)
{
    complex r=a;
    return r+=b;//调用complex::(complex)
}
complex operator+(complex a,double b)
{
    complex r=a;
    return r+=b;//调用complex::(double)
}
complex operator+(double a,complex b)
{
    complex r=b;
    return r+=a;
}
complex operator-(complex a,complex b)
{
    complex r=a;
    return r-=b;
}
complex operator-(complex a,double b)
{
    complex r=a;
    return r+=b;
}
complex operator-(double a,complex b)
{
    complex r=b;
    return r-=a;
}
complex operator*(complex a,complex b)
{
    complex r=a;
    return r*=b;
}
complex operator*(complex a,double b)
{
    complex r=a;
    return r*=b;
}
complex operator*(double a,complex b)
{
    complex r=b;
    return b*=a;
}
complex operator/(complex a,complex b)
{
    complex r=a;
    return a/=b;
}
complex operator/(complex a,double b)
{
    complex r=a;
    return a/=b;
}
complex operator/(double a,complex b)
{
    complex r=b;
    return b/=a;
}

complex operator-(complex a)//一元负号
{
    return a*=(-1);
}
complex operator+(complex a)
{
    return a*=(1);
}
bool operator==(complex a,complex b)
{
    return a.real()==b.real()&&a.imag()==b.imag();
}
bool operator!=(complex a,complex b)
{
    return a.real()!=b.real()||a.imag()==b.imag();

}

std::istream& operator>>(istream& is,complex& a)//输入
{
    cout<<"输入实部和虚部：（以空格分开）"<<endl;
    double r,i;
    is >>r;
    is >>i;
    a.setter_real(r);
    a.setter_imag(i);
}
std::ostream& operator<<(ostream& os,complex &a)//输出
{
    os<<"("<<a.real()<<","<<a.imag()<<")"<<endl;
    return os;
}

