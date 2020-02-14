//�ļ�ժҪ��ʵ������complex
//17130130312 �ܳ���
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
//��������
complex operator+(complex a,complex b)
{
    complex r=a;
    return r+=b;//����complex::(complex)
}
complex operator+(complex a,double b)
{
    complex r=a;
    return r+=b;//����complex::(double)
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

complex operator-(complex a)//һԪ����
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

std::istream& operator>>(istream& is,complex& a)//����
{
    cout<<"����ʵ�����鲿�����Կո�ֿ���"<<endl;
    double r,i;
    is >>r;
    is >>i;
    a.setter_real(r);
    a.setter_imag(i);
}
std::ostream& operator<<(ostream& os,complex &a)//���
{
    os<<"("<<a.real()<<","<<a.imag()<<")"<<endl;
    return os;
}

