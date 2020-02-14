#include<iostream>
#include"function.hpp"
#include<string>

using namespace std;

int main(){
    cout << "please enter data:" << endl;
    string theword;
    Tnode* root=NULL;
    while(cin>>theword){
        regist_word(root,theword);
    }
    cout<<"------------"<<endl;
    print_tree(root,0);
    cout<<"------------"<<endl;
    print_tree_byorder(root);
    bool a=deleteBST(root);
    if(a){
        cout<<"delete successfully!"<<endl;
    }
    return 0;
}


