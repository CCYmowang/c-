//�ļ�ժҪ�������������Ժ���
//17130130312 �ܳ���
//2019.5.25
#include<iostream>
#include"BSTree.hpp"
#include<string>

using namespace std;

int main(){
    cout << "\n*** �����򰴡��������������洢���� ***\n";

    BSTree testTree;
    string newWord;

    cout << "\n���������ɵ��ʣ��ÿո�/����/�Ʊ���ָ�.\n";
    cout << "*** ���� ^z �������� ***\n\n";
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
