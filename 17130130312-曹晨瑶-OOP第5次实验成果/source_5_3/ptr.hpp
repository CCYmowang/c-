//�ļ�ժҪ����������Ptr_to_T
//17130130312 �ܳ���
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
    Ptr_to_T(T* t,T* v,int s);//Լ������Сs������v����ʼֵΪP
    Ptr_to_T(const Ptr_to_T & a);//Լ�����������󣬳�ʼֵΪp
    Ptr_to_T& operator=( const Ptr_to_T& a);

    Ptr_to_T& operator++();//ǰ׺
    Ptr_to_T operator++(int);//��׺

    Ptr_to_T& operator--();
    Ptr_to_T operator--(int);

    T& operator*();
    T* operator->();

};
#endif // CLASS_PTR_HPP
