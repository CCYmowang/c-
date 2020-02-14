//�ļ�ժҪ�������˶�������������
//17130130312 �ܳ���
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

    void destroy();//�������еĽ��
    bool regist(const std::string& newWord);
    bool regist(const char* newWord);
private: //��������������Ϊ˽�еģ�����ֹ BSTree ������и���.
    BSTree(const BSTree&);// �������������趨�壬��Ϊû��ʹ������������
    BSTree& operator=(const BSTree&);
private:
    Tnode* Root;//
    bool deleteBST(Tnode* root);

public:
    //��������
    int regist_word(Tnode* & root,const std::string& newWord);
    void print_pre_order(const Tnode* root,unsigned int indent );
    void print_middle_order(const Tnode* root);

};

#endif // BSTREE_HPP
