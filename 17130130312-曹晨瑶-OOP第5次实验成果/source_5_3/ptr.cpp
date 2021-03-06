//文件摘要：实现了类Ptr_to_T
//17130130312 曹晨瑶
//2019.6.1
#include<iostream>
#include"ptr.hpp"

Ptr_to_T::Ptr_to_T(T* t,T* v,int s) //约束到大小为s的数组v，初始值为p
{
    p=t;
    array=v;
    size=s;
}
Ptr_to_T::Ptr_to_T(const Ptr_to_T &a)//约束到单个对象，初始值为p
{
    p=a.p;
    array=a.array;
    size=a.size;
}
Ptr_to_T& Ptr_to_T::operator=(const Ptr_to_T& a)
{
    p = a.p;
    array = a.array;
    size = a.size;
    return *this;
}
Ptr_to_T& Ptr_to_T::operator++()//前缀
{
    p=p+1;
    return *this;
}
Ptr_to_T Ptr_to_T::operator++(int)//后缀
{
    Ptr_to_T r=*this;
    p=p+1;
    return r;
}
Ptr_to_T& Ptr_to_T::operator--()
{
    p=p-1;
    return *this;
}
Ptr_to_T Ptr_to_T::operator--(int)
{
    Ptr_to_T r=*this;
    p=p-1;
    return r;
}

T& Ptr_to_T::operator*()
{
		return *p;
}
T* Ptr_to_T::operator->()
{
		return p;
}

