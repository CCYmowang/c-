//文件摘要：定义了相关的“异常”类型。
//17130130312 曹晨瑶
//2018.6.18

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <cstdio>
#include <string>
using namespace std;

//表示异常概念的类
class exprException
{
protected :
    long m_where;//在表达式中的哪个地方出错
    string m_strMsg;//错误描述
    exprException() : m_where(-1){}//缺省构造函数
public :
    exprException(const char* msg, long pos) : m_where(pos), m_strMsg(msg)
    {//构造函数
        char buf[10];
        if(m_where>0)
            sprintf(buf,"at %ld",m_where);
        else
            sprintf(buf,"at end");
        m_strMsg += buf;
    }
    virtual ~exprException(){}//析构函数
    const char* what() const//获取错误描述文本
    {
        return m_strMsg.c_str();
    }
    virtual exprException* clone() const//复制对象本身
     {
         exprException* newObject = new exprException(*this);
         return newObject;
     }
};

class CDiv0 : public exprException//除数为0的错误
{
public:
    CDiv0(long pos) : exprException("Divided by zero", pos)
    {}//除数为0
    virtual CDiv0* clone() const
    {
     CDiv0* newObject = new CDiv0( *this );
     return newObject;
    }
protected:  // 允许派生类访问
    CDiv0() {}
};
//表达式存在无效字符
class char_error  : public exprException
 {
 public:
     char_error(char c, long pos) : exprException()
     {
         m_where  = pos;
         m_strMsg = "invalidate char '";
         if( 0x20 < c && c < 126 )  // 对于可打印字符直接拼接
             m_strMsg += c;
         else  // 对于不可打印字符则将其转换为 16进制的表示形式，再拼接
         {
            char buf[10];
            sprintf(buf, "\\X%0X", c & 0xff);
            m_strMsg += buf;
         }
         m_strMsg += "'";
         if( m_where >= 0 )
         {
             char buf[20];
             sprintf(buf, " at %ld", m_where);
             m_strMsg += buf;
         }
     }
     virtual char_error* clone() const
     {
         char_error* newObject = new char_error(*this);
         return newObject;
     }

 protected:  // 允许派生类直接访问
     char_error() {}
 };
//表达式中存在结构错误的类型
class Syntax_error : public exprException
 {
 public:
     Syntax_error(const char* msg, long pos) : exprException(msg, pos)
     {}

     virtual Syntax_error* clone() const
     {
         Syntax_error* newObject = new Syntax_error( *this );
         return newObject;
     }

 protected:  // 允许派生类直接访问
     Syntax_error() {}
 };

#endif // ERROR_H_INCLUDED
