//文件摘要：定义了类Vec4及其接口
//17130130312 曹晨瑶
//2019.6.1
#ifndef CLASS_VEC4_HPP
#define CLASS_VEC4_HPP

using namespace std;

class Vec4
{
    float vec[4];
public:
    Vec4(float a=0,float b=0,float c=0,float d=0){}//default constructor
    Vec4(const Vec4& a);//copy constructor
    Vec4 operator=(const Vec4 a);//复制赋值
    float& operator[](int n);

    //一元操作
    Vec4 operator-(Vec4 a);//一元操作
    Vec4 operator+(Vec4 a);

    Vec4& operator+=(Vec4 a);
    Vec4& operator+=(float a);
    Vec4& operator-=(Vec4 a);
    Vec4& operator-=(float a);
    Vec4& operator*=(Vec4 a);
    Vec4& operator*=(float a);
    Vec4& operator/=(Vec4 a);
    Vec4& operator/=(float a);
    friend Vec4 operator+(Vec4 a,Vec4 b);
    friend Vec4 operator+(Vec4 a,float b);

    friend Vec4 operator-(Vec4 a,Vec4 b);
    friend Vec4 operator-(Vec4,float);

    friend Vec4 operator*(Vec4 a,Vec4 b);
    friend Vec4 operator*(Vec4 a,float b);

    friend Vec4 operator/(Vec4 a,Vec4 b);
    friend Vec4 operator/(Vec4 a,float b);

    friend std::istream& operator>>(istream& in, Vec4& a );  // 输入操作
	friend std::ostream& operator<<(ostream& out,const Vec4& a); // 输出操作

};
Vec4 operator+(Vec4 a,Vec4 b);
Vec4 operator+(Vec4 a,float b);
Vec4 operator-(Vec4 a,Vec4 b);
Vec4 operator-(Vec4,float);
Vec4 operator*(Vec4 a,Vec4 b);
Vec4 operator*(Vec4 a,float b);
Vec4 operator/(Vec4 a,Vec4 b);
Vec4 operator/(Vec4 a,float b);
#endif // CLASS_VEC4_HPP
