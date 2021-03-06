#include<iostream>
#include"function.hpp"
#include<string>

using namespace std;

Tnode* regist_word(Tnode* &root,const string& theword){
    //构造二叉树 操作1
    //根节点的指针的引用
    if(!root){
        //若原树为空，新插入的节点为根节点
        root=new Tnode ;
        root->count=1;
        root->word=theword;
        root->left=NULL;
        root->right=NULL;
    }
    else if(theword==root->word){
        root->count++;
    }
    else if(theword<root->word){
        return regist_word(root->left,theword);
    }
    else if(root->word<theword){
        return regist_word(root->right,theword);
    }
    return root;
}

bool deleteBST(Tnode* root){
    //销毁树
    if(root==NULL){
        return true;
    }
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
    return true;
}
bool search(Tnode* root,const string& theword){
    //查找信息是否存在
    if(!root)
        return false;
    if(root->word==theword)
        return true;
    search(root->left,theword);
    search(root->right,theword);
    return false;
}
void print_tree(Tnode* root,unsigned int indent =0){
    //打印信息 indent树的深度
    if(!root)
        return;
    for(unsigned k=0;k<indent;k++)
        cout <<' ';//右缩进
    cout << root->word << ": " << root->count<<' '<<endl;//打印若干空格，向右缩进
    print_tree(root->left,  indent+1);//递归调用；打印左子树
    if(root->left&&!root->right){
        for(unsigned k=0;k<indent;k++)
            cout<<' ';

        cout<<"<NULL>"<<endl;
        return;
    }
    print_tree(root->right, indent+1);//递归调用；打印右子树
}

void print_tree_byorder(Tnode* root){
    //按字母表顺序输出
    if(root==NULL)
        return;
    print_tree_byorder(root->left);
    cout<<root->word<<": "<<root->count<<' '<<endl;
    print_tree_byorder(root->right);
}
