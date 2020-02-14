//文件摘要：实现了二叉树的结点类型
//17130130312 曹晨瑶
//2019.05.25
#ifndef TNODE_HPP
#define TNODE_HPP

#include<iostream>
#include<string>

class Tnode
{
     public:  // public interface for operations
         Tnode(const char* str =0);     //default constructor
         Tnode(const std::string& str);
         virtual ~Tnode();  // this 'virtual' is introduced in Section 15.6 of Text book

         // 仅输出当前结点自身的信息。而整颗树的输出则由 BSTree 负责.
         //   参数 outFile 为输出目标文件
         void print(std::ostream& outFile) const;

     public:

         void setWord(const std::string& val) { word = val; }

         const std::string& getWord() const { return word; }

         std::string& getWord() { return word; }

         void setLeft(Tnode* val) { left = val; }
         // return the pointer to const left child of const Tnode
         const Tnode* getLeft() const { return left; }
         // return the non-const reference to left child of non-const Tnode
         Tnode*& getLeft() { return left; }

         void setRight(Tnode* val) { right = val; }
         const Tnode* getRight() const { return right; }
         Tnode*& getRight() { return right; }

         void setCount(int val) { count = val; }
         int  getCount() const { return count; }
         int& getCount()      { return count; }

     private: //这两个对象复制操作声明为私有的，以阻止 Tnode 对象被复制.
         Tnode(const Tnode&);    // 仅需声明，无需定义，因为没有使用这两个函数
         Tnode& operator=(const Tnode&);

     private:
         std::string word; // the text in this node
         int count;        // appear times of word in input
         Tnode* left;      // left  child
         Tnode* right;     // right child
}; // end of class Tnode


#endif // TNODE_HPP
