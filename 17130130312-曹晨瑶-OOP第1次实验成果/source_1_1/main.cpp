//ժҪ������������ֺ����Ӧ��ֵ�����ͬһ�����ֳ��ֵĴ����Ͷ�Ӧֵ�ĺͺ�ƽ����������������ֵ�ֵ�ĺͺ�ƽ������
//���ߣ�17130130312 �ܳ���
//ʱ�䣺2019.4.13
#include <iostream>
#include<string>
#include"test.h"
using namespace std;
const int SIZE=30;//���ṹ�������С����Ϊ����
static wordinfo myDictionary[SIZE];//��¼���ظ����ּ�����Ϣ
int main(){
    int i=0;//������
    int key=0;//������������myDictionary���Ѿ����ڵ���Ϣ����
    string name;//���������������
    double value=0;//�������������ֶ�Ӧ��ֵ
    double sum_sum=0;//�ܺ�
    int sum_count=0;//����������
    while(cin>>name>>value){//����ctrl+z��������
        //�������������myDictionary�д��ڵ�����һһ�Ա�
        for(i=0;i<key;i++){
            if(name != myDictionary[i].name)//����ͬ���ж���һ��
                continue;//ֱ�������еĶԱ���
            else{//��ͬ �ض����Ƶĸ����ܺͼ�1��sum+value
                myDictionary[i].name_count++;
                myDictionary[i].sum += value;
                break;//����forѭ��
            }
        }
        //����������ֲ���myDictionary�У������������
        if (myDictionary[i].name_count ==0){
            myDictionary[i].name = name;
			myDictionary[i].name_count++;
			myDictionary[i].sum += value;
			key++;
        }
    }
    cout<<"����ǣ�"<<endl;
	for (int i = 0; i<key; i++)
	{
		sum_sum += myDictionary[i].sum;
        sum_count += myDictionary[i].name_count;
		cout<<myDictionary[i].name<<" Sum="<<myDictionary[i].sum<<'\t';
		cout<<"Avg="<<myDictionary[i].sum/myDictionary[i].name_count<<endl;
	}
	cout<<"�ܼƣ�"<<endl;
	cout<<"All_Sum="<<sum_sum<<",ALL_Avg="<<sum_sum/sum_count<<endl;
	return 0;
}

