//摘要：输入多组名字和其对应的值，输出同一个名字出现的次数和对应值的和和平均数。输出所有名字的值的和和平均数。
//作者：17130130312 曹晨瑶
//时间：2019.4.13
#include <iostream>
#include<string>
#include"test.h"
using namespace std;
const int SIZE=30;//将结构体数组大小定义为常量
static wordinfo myDictionary[SIZE];//记录不重复名字及其信息
int main(){
    int i=0;//计数器
    int key=0;//计数器，计数myDictionary中已经存在的信息个数
    string name;//变量，输入的名字
    double value=0;//变量，输入名字对应的值
    double sum_sum=0;//总和
    int sum_count=0;//输入总数；
    while(cin>>name>>value){//输入ctrl+z结束输入
        //将输入的名字与myDictionary中存在的名字一一对比
        for(i=0;i<key;i++){
            if(name != myDictionary[i].name)//不相同，判断下一个
                continue;//直到与所有的对比完
            else{//相同 特定名称的个数总和加1，sum+value
                myDictionary[i].name_count++;
                myDictionary[i].sum += value;
                break;//跳出for循环
            }
        }
        //若输入的名字不在myDictionary中，将其存入其中
        if (myDictionary[i].name_count ==0){
            myDictionary[i].name = name;
			myDictionary[i].name_count++;
			myDictionary[i].sum += value;
			key++;
        }
    }
    cout<<"结果是："<<endl;
	for (int i = 0; i<key; i++)
	{
		sum_sum += myDictionary[i].sum;
        sum_count += myDictionary[i].name_count;
		cout<<myDictionary[i].name<<" Sum="<<myDictionary[i].sum<<'\t';
		cout<<"Avg="<<myDictionary[i].sum/myDictionary[i].name_count<<endl;
	}
	cout<<"总计："<<endl;
	cout<<"All_Sum="<<sum_sum<<",ALL_Avg="<<sum_sum/sum_count<<endl;
	return 0;
}

