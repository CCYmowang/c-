#ifndef Expression_hpp_
#define Expression_hpp_
class Expression
{
    //把操作数等统称为表达式类
public:
    //方便起见，暂时都为公有
    bool IsNumber;      //是否数字
    double Number;         //数字内容，  IsNumber==true有效
    char Operator;      //操作符内容，IsNumber==false有效
    Expression* Left;   //左表达式，  IsNumber==false有效
    Expression* Right;  //右表达式，  IsNumber==false有效

    Expression(double aNumber);
    Expression* GetNumber(char*& Stream);
    Expression* GetTerm(char*& Stream);
    Expression* GetFactor(char*& Stream);
    Expression* GetExp(char*& Stream);
    Expression(char aOperator , Expression* aLeft , Expression* aRight);
    void PrintDLR();//遍历树
    void PrintLDR();
    void PrintLRD();
    double calculate();//计算结果

    //析构函数递归释放所有内容
    ~Expression();
};
#endif // Expression_hpp_
