//文件摘要：实现了类Vec4
//17130130312 曹晨瑶
//2019.6.1

#include<iostream>
#include"Vec4.hpp"

using namespace std;
/*Vec4::Vec4(float a =0,float b =0,float c =0,float d =0)
{
    vec[0]=a;
    vec[1]=b;
    vec[2]=c;
    vec[3]=d;
}*/

Vec4::Vec4(const Vec4& a)//copy constructor
{
    vec[0]=a.vec[0];
    vec[1]=a.vec[1];
    vec[2]=a.vec[2];
    vec[3]=a.vec[3];
}

Vec4 Vec4::operator=(const Vec4 a)//复制赋值
{
    vec[0]=a.vec[0];
    vec[1]=a.vec[1];
    vec[2]=a.vec[2];
    vec[3]=a.vec[3];
    return *this;
}

float& Vec4::operator[](int n)
{
    if(n<0) return vec[0];
    if(n>3) return vec[3];
    return vec[n];
}

//一元操作
Vec4  Vec4::operator-(Vec4 a)
{
    vec[0]=a.vec[0]*-1;
    vec[1]=a.vec[1]*-1;
    vec[2]=a.vec[2]*-1;
    vec[3]=a.vec[3]*-1;
    return *this;
}
Vec4  Vec4::operator+(Vec4 a)
{
    return *this;
}

Vec4& Vec4::operator+=(Vec4 a)
{
    vec[0]+=a.vec[0];
    vec[1]+=a.vec[1];
    vec[2]+=a.vec[2];
    vec[3]+=a.vec[3];
    return *this;
}
Vec4& Vec4::operator+=(float a)
{
    vec[0]+=a;
    vec[1]+=a;
    vec[2]+=a;
    vec[3]+=a;
    return *this;
}
Vec4& Vec4::operator-=(Vec4 a)
{
    vec[0]-=a.vec[0];
    vec[1]-=a.vec[1];
    vec[2]-=a.vec[2];
    vec[3]-=a.vec[3];
    return *this;
}
Vec4& Vec4::operator-=(float a)
{
    vec[0]-=a;
    vec[1]-=a;
    vec[2]-=a;
    vec[3]-=a;
    return *this;
}
Vec4& Vec4::operator*=(Vec4 a)
{
    vec[0]*=a.vec[0];
    vec[1]*=a.vec[1];
    vec[2]*=a.vec[2];
    vec[3]*=a.vec[3];
    return *this;
}
Vec4& Vec4::operator*=(float a)
{
    vec[0]*=a;
    vec[1]*=a;
    vec[2]*=a;
    vec[3]*=a;
    return *this;
}
Vec4& Vec4::operator/=(Vec4 a)
{
    vec[0]/=a.vec[0];
    vec[1]/=a.vec[1];
    vec[2]/=a.vec[2];
    vec[3]/=a.vec[3];
    return *this;
}
Vec4& Vec4::operator/=(float a)
{
    vec[0]/=a;
    vec[1]/=a;
    vec[2]/=a;
    vec[3]/=a;
    return *this;
}
Vec4 operator+(Vec4 a,Vec4 b)
{
    Vec4 r=a;
    return r+=b;
}
Vec4 operator+(Vec4 a,float b)
{
    Vec4 r=a;
    return r+=b;
}
Vec4 operator-(Vec4 a,Vec4 b)
{
    Vec4 r=a;
    return r-=b;
}
Vec4 operator-(Vec4 a,float b)
{
    Vec4 r=a;
    return r-=b;
}
Vec4 operator*(Vec4 a,Vec4 b)
{
    Vec4 r=a;
    return r*=b;
}
Vec4 operator*(Vec4 a,float b)
{
    Vec4 r=a;
    return r*=b;
}
Vec4 operator/(Vec4 a,Vec4 b)
{
    Vec4 r=a;
    return r/=b;
}
Vec4 operator/(Vec4 a,float b)
{
    Vec4 r=a;
    return r/=b;
}

std::istream& operator>>(istream& in, Vec4& a )
{
    cout<<"四个数之间用空格分开："<<endl;
    in>>a.vec[0]>>a.vec[1]>>a.vec[2]>>a.vec[3];
    return in;
}
std::ostream& operator<<(ostream& out,const Vec4& a)
{
    out<<"("<<a.vec[0]<<","<<a.vec[1]<<","<<a.vec[2]<<","<<a.vec[3]<<")";
    return out;
}
