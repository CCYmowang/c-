//�ļ�ժҪ����������صġ��쳣�����͡�
//17130130312 �ܳ���
//2018.6.18

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <cstdio>
#include <string>
using namespace std;

//��ʾ�쳣�������
class exprException
{
protected :
    long m_where;//�ڱ��ʽ�е��ĸ��ط�����
    string m_strMsg;//��������
    exprException() : m_where(-1){}//ȱʡ���캯��
public :
    exprException(const char* msg, long pos) : m_where(pos), m_strMsg(msg)
    {//���캯��
        char buf[10];
        if(m_where>0)
            sprintf(buf,"at %ld",m_where);
        else
            sprintf(buf,"at end");
        m_strMsg += buf;
    }
    virtual ~exprException(){}//��������
    const char* what() const//��ȡ���������ı�
    {
        return m_strMsg.c_str();
    }
    virtual exprException* clone() const//���ƶ�����
     {
         exprException* newObject = new exprException(*this);
         return newObject;
     }
};

class CDiv0 : public exprException//����Ϊ0�Ĵ���
{
public:
    CDiv0(long pos) : exprException("Divided by zero", pos)
    {}//����Ϊ0
    virtual CDiv0* clone() const
    {
     CDiv0* newObject = new CDiv0( *this );
     return newObject;
    }
protected:  // �������������
    CDiv0() {}
};
//���ʽ������Ч�ַ�
class char_error  : public exprException
 {
 public:
     char_error(char c, long pos) : exprException()
     {
         m_where  = pos;
         m_strMsg = "invalidate char '";
         if( 0x20 < c && c < 126 )  // ���ڿɴ�ӡ�ַ�ֱ��ƴ��
             m_strMsg += c;
         else  // ���ڲ��ɴ�ӡ�ַ�����ת��Ϊ 16���Ƶı�ʾ��ʽ����ƴ��
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

 protected:  // ����������ֱ�ӷ���
     char_error() {}
 };
//���ʽ�д��ڽṹ���������
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

 protected:  // ����������ֱ�ӷ���
     Syntax_error() {}
 };

#endif // ERROR_H_INCLUDED
