//�ļ�ժҪ�������Ժ���
//17130130312 �ܳ���
//2019.6.18
#include <iostream>
#include<string>
#include"animal.hpp"
using namespace std;

int main()
{
    cout<<"****������԰****"<<endl;
    Animal A("Animal");
    Cat C("cat_tidy");
    Dog D("dog_tidy");
	A.iam(); A.hello(); A.common();
	C.iam(); C.hello(); C.common();
	D.iam(); D.hello(); D.common();
	Animal *p = &A;
	Animal *q = &C;
	Animal *s = &D;
	cout << "**********ָ��" << endl;
	p->iam(); p->hello(); p->common();
	q->iam(); q->hello(); q->common();
	s->iam(); s->hello(); s->common();
	Animal & z = A;
	Animal & x = C;
	Animal & c = D;
	cout << "***********����" << endl;
	z.iam(); z.hello(); z.common();
	x.iam(); x.hello(); x.common();
	c.iam(); c.hello(); c.common();
    return 0;
}
