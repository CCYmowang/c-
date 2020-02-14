#ifndef Expression_hpp_
#define Expression_hpp_
class Expression
{
    //�Ѳ�������ͳ��Ϊ���ʽ��
public:
    //�����������ʱ��Ϊ����
    bool IsNumber;      //�Ƿ�����
    double Number;         //�������ݣ�  IsNumber==true��Ч
    char Operator;      //���������ݣ�IsNumber==false��Ч
    Expression* Left;   //����ʽ��  IsNumber==false��Ч
    Expression* Right;  //�ұ��ʽ��  IsNumber==false��Ч

    Expression(double aNumber);
    Expression* GetNumber(char*& Stream);
    Expression* GetTerm(char*& Stream);
    Expression* GetFactor(char*& Stream);
    Expression* GetExp(char*& Stream);
    Expression(char aOperator , Expression* aLeft , Expression* aRight);
    void PrintDLR();//������
    void PrintLDR();
    void PrintLRD();
    double calculate();//������

    //���������ݹ��ͷ���������
    ~Expression();
};
#endif // Expression_hpp_
