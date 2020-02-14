//�ļ�ժҪ��������complex��Ľӿ�
//17130130312 �ܳ���
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
    friend istream& operator>>(istream& is,complex& a);//����
    friend ostream& operator<<(ostream& os,complex& a);//���
};
//��������
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

complex operator-(complex a);//һԪ����
complex operator+(complex a);
bool operator==(complex a,complex b);
bool operator!=(complex a,complex b);

std::istream& operator>>(std::istream& input,complex& a);//����
std::ostream& operator<<(std::ostream& output,complex& a);//���



#endif // COMPLEX _CLASS_HPP
