//文件摘要：主控模块，定义了对表达式类型 Expr 的测试程序。
//17130130312 曹晨瑶
//2018.6.18

#include <iostream>
#include <cmath>
#include "Expr.hpp"
using namespace std;

class expr_testcase//对单个表达式的测试类
{
public:
    enum test_err_kind//表达式错误类型的种类
    {
     ERR_NONE,     //表达式没有错误
     ERR_UNKNOWN,  //表达式出现未知错误
     ERR_VALUE,    //表达式的值计算错误

     EX_UNKNOWN,   //未知类型的异常
     EX_SYNTAX,    //语法错误 类异常
     EX_CHAR,      //无效字符类异常
     EX_DIV0       //除数为0类异常
    };
private:
     string   mExprText;//被测试的表达式文本
     test_err_kind mExpectedErrKind;//表达式错误种类
     double        mExpectedValue;//期待的表达式的值

     test_err_kind mErrKind;//测试中出现的异常种类
     double        mValue;//测试所得表达式的值
     string   mErrorMsg;//测试时发生的错误描述

     bool  passed;//测试结果是否正确

     void setError(test_err_kind ek, const char* msg)//设置错误信息
     {
         mErrKind = ek;
         mErrorMsg.assign( msg );
     }
     bool test_parse(Expr& testee)//测试表达式的解析操作
     {
         cout << "Try to parse expression \"" << mExprText << "\"" << endl ;
         try
         {
             testee.setText(mExprText.c_str());//对表达式进行解析
             return true;
         }
         catch(Syntax_error& ex)  // 先尝试捕捉特定子类对象，表达式结构错误
         {
             setError(EX_SYNTAX, ex.what());
             cout << "Found 'Syntax_error' exception: "
                  << ex.what() << endl;
         }
         catch(char_error& ex)  // 再尝试捕捉另一个特定子类对象，无效字符
         {
             setError(EX_CHAR, ex.what());
             cout << "Found 'char_error' exception: "
                  << ex.what() << endl;
         }
         catch(exprException& ex) // 最后再尝试捕捉父类对象，异常类
         {
             setError(EX_UNKNOWN, ex.what());
             cout << "Found 'exprException' exception: "
                  << ex.what() << endl;
         }
         catch( ... ) // 捕获其他未知 异常( catch all )
         {
             setError(EX_UNKNOWN, "解析表达式时发生了未知异常");
             cout <<mErrorMsg << ".\n";
         }
         return false;
     }
     bool test_print(Expr& testee)//测试表达式的打印操作
     {
         cout << "Try to print expression \"" << testee.getText() << "\"" << endl ;
         try
         {
             testee.printTree(cout); // 打印表达式的语法树
             cout << "\t Infix  notation: [" << testee.print_in_fix()    << "]\n";
             cout << "\tPostfix notation: [" << testee.print_post_fix()  << "]\n";
             cout << "\tPrefix  notation: [" << testee.prin_pre_fix()   << "]\n";
             return true;
         }
         catch(...)
         {
             setError(EX_UNKNOWN, "打印表达式时发生了未知异常");
             cout << mErrorMsg << ".\n";
             return false;
         }
     }
     bool test_eval(Expr& testee)//测试表达式求值时的错误
     {
         cout << "Try to evaluate expression \"" << testee.getText() << "\"" << endl ;
         try
         {
             mValue = testee.eval() ;
             cout << "\t表达式的值: [" << mValue << "]，期望值:"
                  << mExpectedValue << endl;

             // 将Expr所求的值与正确值进行对比，以验证实现的正确性.
             if( fabs(mExpectedValue - mValue) < 0.00001 )
             {
                 return true;
             }
             else
             {
                 setError(ERR_VALUE, "表达式的值计算不正确");
             }
         }
         catch(CDiv0& ex)
         {
             setError(EX_DIV0, ex.what());
         }
         catch(...)
         {
             setError(EX_UNKNOWN, "表达式求值时发生了未知异常");
         }
         cout << "\007O," << mErrorMsg << ".\n";
         return false;
     }
public:
     expr_testcase(const char*  exprText, double  expectedValue, test_err_kind ek =ERR_NONE)
             : mExprText(exprText), mExpectedErrKind(ek),
               mExpectedValue(expectedValue), mErrKind(ERR_UNKNOWN),
               mValue(0), passed(false)
     {}//构造函数
     int run()//执行一个测试用例
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
                 cout << "错误一致:" << mErrorMsg;
             else
                 cout << "没有错误";
             cout << ".\n";
         }
         else
         {
             // class Expr 或其辅助程序有 BUG!!!
             passed =false;
             cout << "TEST *** failed ***. 错误信息:";
             if( !(mErrorMsg.empty()) )
                 cout << mErrorMsg;
             else
                 cout << "N/A";
             cout << ".\n";
         }

         cout << "--------------------------------------------------------------\n\n";

         if( passed )
             if( mErrKind == ERR_NONE )
                 return 0;  // 表达式没有错误，计算正确
             else
                 return 1;  // 表达式有错误且一致，计算正确
         else
             return -1;     // 实现的 Expr 或其辅助程序有 BUG.
     }
 };

class expr_testcase_runner//测试用例的执行器
{
 public:
     void run()
     {
         // 定义测试用例集.
         expr_testcase  allTestCases[] =
         {
         // 测试 若干没有错误的表达式
             expr_testcase( "1+2",   3,  expr_testcase::ERR_NONE ),
             expr_testcase( "1+2*3", 7,  expr_testcase::ERR_NONE ),
             expr_testcase( "(1++2)*-3.3", -9.9, expr_testcase::ERR_NONE ),
             expr_testcase( "3.1415926+(1.0/.3)*10",
                            3.1415926 + 33.33333333333333333, expr_testcase::ERR_NONE ),
             expr_testcase( "(--5+3)*-4\n789" ,  // 换行符等同于分号，均表示表达式的结束
                            -32, expr_testcase::ERR_NONE ),
             expr_testcase( "",    0, expr_testcase::ERR_NONE ),
             expr_testcase( ";+5", // 因为分号被看作表达式结束标志，所以该表达式被认为空
                            0, expr_testcase::ERR_NONE ),

         // 测试 若干存在错误的表达式
             expr_testcase( ")",          // 多了右括弧，因为没有与之匹配的左括弧
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "1)",         // 多了右括弧，因为没有与之匹配的左括弧
                            1, expr_testcase::EX_SYNTAX ),
             expr_testcase( "(2+1))",     // 多了右括弧，因为没有与之匹配的左括弧
                            3, expr_testcase::EX_SYNTAX ),
             expr_testcase( "(1.0/.3*10",  //末尾缺少右括弧
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "1...0/.3*10", //第2个 . 不应该出现
                            0, expr_testcase::EX_SYNTAX ),
             expr_testcase( "5 + A*10",    //不支持标识符（注：第6章代码是支持的）
                            0, expr_testcase::EX_CHAR ),
             expr_testcase( "5/0",         // 除数为0
                            0, expr_testcase::EX_DIV0 ),
             expr_testcase( "5/(12-12)",     // 除数为0
                            0, expr_testcase::EX_DIV0 ),
             expr_testcase( "(--5++3*)-4" , // 乘号右边应跟随一个操作数
                            0, expr_testcase::EX_SYNTAX )
         };
         size_t n = sizeof(allTestCases) / sizeof(allTestCases[0]);
         action( allTestCases, n );
     }

 private:
     void action(expr_testcase *pAllCases,  size_t  sz)//执行全部测试用例
     {
         int  n_passed =0;  // 通过测试的用例数
         int  n_passed_noerr =0; // 通过测试但表达式有错误的用例数量
         int  n_fail  =0; // 未通过测试的用例数

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

         cout << "\n共执行测试用例 " << sz << "个，其中:\n"
              << "    " << n_fail << " 个测试未通过，\n"
              << "    " << n_passed << " 个测试通过，其中:\n"
              << "        " << n_passed_noerr << " 个  正确的表达式测试通过，\n"
              << "        " << n_passed-n_passed_noerr << " 个不正确的表达式测试通过."
              << "\n";

           cout << "\n****************************************\n";
         if( n_fail != 0 )
         {
             cout << "*  这个程序的实现 怎么有 BUG 呢 @_@    *";
         }
         else
         {
             cout << "*  没有发现这个程序的实现有错误 ^_^    *";
         }
         cout << "\n****************************************\n";
     }

 };



 int main()
 {
     expr_testcase_runner  driver;
     driver.run( );//调用测试函数
     return 0;
 }
