#ifndef test
#define test
#include<iostream>
#include<cstring>
using namespace std;
struct wordinfo{
    string name;//特定名字
    double sum;//同一名称的总和
    int name_count;//给特定名称计数
    wordinfo(){
        //name=NULL;
        sum=0;
        name_count=0;
    }//构造函数，初始化
};


#endif // test
