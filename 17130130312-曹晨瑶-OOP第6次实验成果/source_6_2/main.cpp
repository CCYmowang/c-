//�ļ�ժҪ������ģ�飬�����˶Ա��ʽ���� Expr �Ĳ��Գ���
//17130130312 �ܳ���
//2018.6.18

#include <iostream>
#include <cmath>
#include "Expr.hpp"
using namespace std;

class expr_testcase//�Ե������ʽ�Ĳ�����
{
public:
    enum test_err_kind//���ʽ�������͵�����
    {
     ERR_NONE,     //���ʽû�д���
     ERR_UNKNOWN,  //���ʽ����δ֪����
     ERR_VALUE,    //���ʽ��ֵ�������

     EX_UNKNOWN,   //δ֪���͵��쳣
     EX_SYNTAX,    //�﷨���� ���쳣
     EX_CHAR,      //��Ч�ַ����쳣
     EX_DIV0       //����Ϊ0���쳣
    };
private:
     string   mExprText;//�����Եı��ʽ�ı�
     test_err_kind mExpectedErrKind;//���ʽ��������
     double        mExpectedValue;//�ڴ��ı��ʽ��ֵ

     test_err_kind mErrKind;//�����г��ֵ��쳣����
     double        mValue;//�������ñ��ʽ��ֵ
     string   mErrorMsg;//����ʱ�����Ĵ�������

     bool  passed;//���Խ���Ƿ���ȷ

     void setError(test_err_kind ek, const char* msg)//���ô�����Ϣ
     {
         mErrKind = ek;
         mErrorMsg.assign( msg );
     }
     bool test_parse(Expr& testee)//���Ա��ʽ�Ľ�������
     {
         cout << "Try to parse expression \"" << mExprText << "\"" << endl ;
         try
         {
             testee.setText(mExprText.c_str());//�Ա��ʽ���н���
             return true;
         }
         catch(Syntax_error& ex)  // �ȳ��Բ�׽�ض�������󣬱��ʽ�ṹ����
         {
             setError(EX_SYNTAX, ex.what());
             cout << "Found 'Syntax_error' exception: "
                  << ex.what() << endl;
         }
         catch(char_error& ex)  // �ٳ��Բ�׽��һ���ض����������Ч�ַ�
         {
             setError(EX_CHAR, ex.what());
             cout << "Found 'char_error' exception: "
                  << ex.what() << endl;
         }
         catch(exprException& ex) // ����ٳ��Բ�׽��������쳣��
         {
             setError(EX_UNKNOWN, ex.what());
             cout << "Found 'exprException' exception: "
                  << ex.what() << endl;
         }
         catch( ... ) // ��������δ֪ �쳣( catch all )
         {
             setError(EX_UNKNOWN, "�������ʽʱ������δ֪�쳣");
             cout <<mErrorMsg << ".\n";
         }
         return false;
     }
     bool test_print(Expr& testee)//���Ա��ʽ�Ĵ�ӡ����
     {
         cout << "Try to print expression \"" << testee.getText() << "\"" << endl ;
         try
         {
             testee.printTree(cout); // ��ӡ���ʽ���﷨��
             cout << "\t Infix  notation: [" << testee.print_in_fix()    << "]\n";
             cout << "\tPostfix notation: [" << testee.print_post_fix()  << "]\n";
             cout << "\tPrefix  notation: [" << testee.prin_pre_fix()   << "]\n";
             return true;
         }
         catch(...)
         {
             setError(EX_UNKNOWN, "��ӡ���ʽʱ������δ֪�쳣");
             cout << mErrorMsg << ".\n";
             return false;
         }
     }
     bool test_eval(Expr& testee)//���Ա��ʽ��ֵʱ�Ĵ���
     {
         cout << "Try to evaluate expression \"" << testee.getText() << "\"" << endl ;
         try
         {
             mValue = testee.eval() ;
             cout << "\t���ʽ��ֵ: [" << mValue << "]������ֵ:"
                  << mExpectedValue << endl;

             // ��Expr�����ֵ����ȷֵ���жԱȣ�����֤ʵ�ֵ���ȷ��.
             if( fabs(mExpectedValue - mValue) < 0.00001 )
             {
                 return true;
             }
             else
             {
                 setError(ERR_VALUE, "���ʽ��ֵ���㲻��ȷ");
             }
         }
         catch(CDiv0& ex)
         {
             setError(EX_DIV0, ex.what());
         }
         catch(...)
         {
             setError(EX_UNKNOWN, "���ʽ��ֵʱ������δ֪�쳣");
         }
         cout << "\007O," << mErrorMsg << ".\n";
         return false;
     }
public:
     expr_testcase(const char*  exprText, double  expectedValue, test_err_kind ek =ERR_NONE)
             : mExprText(exprText), mExpectedErrKind(ek),
               mExpectedValue(expectedValue), mErrKind(ERR_UNKNOWN),
               mValue(0), passed(false)
     {}//���캯��
     int run()//ִ��һ����������
     {
         cout << "TEST expression text [" << mExprText << "]\n";
         Expr testeeObject;
         if( test_parse(testeeObject) &&
             test_print(testeeObject) &&
             test_eval (testeeObject)
           )
         {
             mErrKind = ERR_NONE;
         }

         if( mErrKind ==  mExpectedErrKind)
         {
             passed =true;
             cout << "TEST *** passed *** ";
             if( !(mErrorMsg.empty()) )
                 cout << "����һ��:" << mErrorMsg;
             else
                 cout << "û�д���";
             cout << ".\n";
         }
         else
         {
             // class Expr ���丨�������� BUG!!!
             passed =false;
             cout << "TEST *** failed ***. ������Ϣ:";
             if( !(mErrorMsg.empty()) )
                 cout << mErrorMsg;
             else
                 cout << "N/A";
             cout << ".\n";
         }

         cout << "--------------------------------------------------------------\n\n";

         if( passed )
             if( mErrKind == ERR_NONE )
                 return 0;  // ���ʽû�д��󣬼�����ȷ
             else
                 return 1;  // ���ʽ�д�����һ�£�������ȷ
         else
             return -1;     // ʵ�ֵ� Expr ���丨�������� BUG.
     }
 };

class expr_testcase_runner//����������ִ����
{
 public:
     void run()
     {
         // �������������.
         expr_testcase  allTestCases[] =
         {
         // ���� ����û�д���ı��ʽ
             expr_testcase( "1+2",   3,  expr_testcase::ERR_NONE ),
             expr_testcase( "1+2*3", 7,  expr_testcase::ERR_NONE ),
             expr_testcase( "(1++2)*-3.3", -9.9, expr_testcase::ERR_NONE ),
             expr_testcase( "3.1415926+(1.0/.3)*10",
                            3.1415926 + 33.33333333333333333, expr_testcase::ERR_NONE ),
             expr_testcase( "(--5+3)*-4\n789" ,  // ���з���ͬ�ڷֺţ�����ʾ���ʽ�Ľ���
                            -32, expr_testcase::ERR_NONE ),
             expr_testcase( "",    0, expr_testcase::ERR_NONE ),
             expr_testcase( ";+5", // ��Ϊ�ֺű��������ʽ������־�����Ըñ��ʽ����Ϊ��
                            0, expr_testcase::ERR_NONE ),

         // ���� ���ɴ��ڴ���ı��ʽ
             expr_testcase( ")",          // ��������������Ϊû����֮ƥ���������
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "1)",         // ��������������Ϊû����֮ƥ���������
                            1, expr_testcase::EX_SYNTAX ),
             expr_testcase( "(2+1))",     // ��������������Ϊû����֮ƥ���������
                            3, expr_testcase::EX_SYNTAX ),
             expr_testcase( "(1.0/.3*10",  //ĩβȱ��������
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "1...0/.3*10", //��2�� . ��Ӧ�ó���
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "5 + A*10",    //��֧�ֱ�ʶ����ע����6�´�����֧�ֵģ�
                            0, expr_testcase::EX_CHAR ),
             expr_testcase( "5/0",         // ����Ϊ0
                            0, expr_testcase::EX_DIV0 ),
             expr_testcase( "5/(12-12)",     // ����Ϊ0
                            0, expr_testcase::EX_DIV0 ),
             expr_testcase( "(--5++3*)-4" , // �˺��ұ�Ӧ����һ��������
                            0, expr_testcase::EX_SYNTAX )
         };
         size_t n = sizeof(allTestCases) / sizeof(allTestCases[0]);
         action( allTestCases, n );
     }

 private:
     void action(expr_testcase *pAllCases,  size_t  sz)//ִ��ȫ����������
     {
         int  n_passed =0;  // ͨ�����Ե�������
         int  n_passed_noerr =0; // ͨ�����Ե����ʽ�д������������
         int  n_fail  =0; // δͨ�����Ե�������

         expr_testcase * ptr = pAllCases;
         for(size_t i=0; i<sz; ++i)
         {
             switch( ptr->run() )
             {
             case 0:    ++n_passed; ++n_passed_noerr;
                 break;
             case 1:    ++n_passed;
                 break;
             default:   ++n_fail;
                 break;
             }
             ++ptr;
         }

         cout << "\n��ִ�в������� " << sz << "��������:\n"
              << "    " << n_fail << " ������δͨ����\n"
              << "    " << n_passed << " ������ͨ��������:\n"
              << "        " << n_passed_noerr << " ��  ��ȷ�ı��ʽ����ͨ����\n"
              << "        " << n_passed-n_passed_noerr << " ������ȷ�ı��ʽ����ͨ��."
              << "\n";

           cout << "\n****************************************\n";
         if( n_fail != 0 )
         {
             cout << "*  ��������ʵ�� ��ô�� BUG �� @_@    *";
         }
         else
         {
             cout << "*  û�з�����������ʵ���д��� ^_^    *";
         }
         cout << "\n****************************************\n";
     }

 };



 int main()
 {
     expr_testcase_runner  driver;
     driver.run( );//���ò��Ժ���
     return 0;
 }
