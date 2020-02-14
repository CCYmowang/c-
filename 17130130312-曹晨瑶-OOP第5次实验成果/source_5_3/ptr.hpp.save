//文件摘要：定义了类Ptr_to_T
//17130130312 曹晨瑶
//2019.6.1

#ifndef CLASS_PTR_HPP
#define CLASS_PTR_HPP
using namespace std;

struct T
{
    int m;

};
class Ptr_to_T
{
private:
    T* p;
    T* array;
    int size;
public:
    Ptr_to_T(T* t,T* v,int s);//约束到大小s的数组v，初始值为P
    Ptr_to_T(const Ptr_to_T & a);//约束到单个对象，初始值为p
    Ptr_to_T& operator=( const Ptr_to_T& a);

    Ptr_to_T& operator++();//前缀
    Ptr_to_T operator++(int);//后缀

    Ptr_to_T& operator--();
    Ptr_to_T operator--(int);

    T& operator*();
    T* operator->();

};
#endif // CLASS_PTR_HPP
