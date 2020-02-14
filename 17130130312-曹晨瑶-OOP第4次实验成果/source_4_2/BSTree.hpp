//文件摘要：定义了二叉树排序类型
//17130130312 曹晨瑶
//2019.5.29
#ifndef BSTREE_HPP
#define BSTREE_HPP

#include<iostream>
#include<string>

class Tnode;
class BSTree
{
public:
    BSTree();
    virtual ~BSTree();

    void destroy();//销毁树中的结点
    bool regist(const std::string& newWord);
    bool regist(const char* newWord);
private: //这两个操作定义为私有的，以阻止 BSTree 对象进行复制.
    BSTree(const BSTree&);// 仅需声明，无需定义，因为没有使用这两个函数
    BSTree& operator=(const BSTree&);
private:
    Tnode* Root;//
    bool deleteBST(Tnode* root);

public:
    //辅助函数
    int regist_word(Tnode* & root,const std::string& newWord);
    void print_pre_order(const Tnode* root,unsigned int indent );
    void print_middle_order(const Tnode* root);

};

#endif // BSTREE_HPP
