//文件摘要：主函数，测试函数
//17130130312 曹晨瑶
//2019.5.25
#include<iostream>
#include"BSTree.hpp"
#include<string>

using namespace std;

int main(){
    cout << "\n*** 本程序按【二叉排序树】存储单词 ***\n";

    BSTree testTree;
    string newWord;

    cout << "\n请输入若干单词，用空格/换行/制表符分隔.\n";
    cout << "*** 输入 ^z 结束输入 ***\n\n";
    Tnode* root=NULL;
    while(cin>>newWord){
        testTree.regist_word(root,newWord);
    }
    cout<<"------------"<<endl;
    testTree.print_pre_order(root,0);
    cout<<"------------"<<endl;
    testTree.print_middle_order(root);
    return 0;
}
