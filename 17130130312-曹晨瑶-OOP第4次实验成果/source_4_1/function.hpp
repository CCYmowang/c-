//�ļ�ժҪ�����ڼ������ӿ�
//17130130312 �ܳ���
//2019.5.29
#ifndef CLASS_DATE_HPP
#define CLASS_DATE_HPP
using namespace std;
class Date{
public:
    //ȱʡ����
    Date(int y,int m,int d);//�ա��¡��� ��ʼ��
    Date(int m, int d);//�ա��¡�����
    Date(int dd);//�ա����ꡢ����
    Date();//���ձ��±���

    //�޸�Date�ĺ���
    void add_day(int n);//��n��
    void add_month(int n);//��n��
    void add_year(int n);//��n��
    void print_date();//�������
private:
    int days;//��1970��1��1������������
};

int isleapyear(int year);//�ж��Ƿ�������
void days_to_date(int new_days,int* y,int* m,int* d);
int date_to_days(int y,int m,int d);

#endif // CLASS_DATE_HPP
