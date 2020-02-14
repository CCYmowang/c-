//�ļ�ժҪ��ʵ���˶������Ľ������
//17130130312 �ܳ���
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

         // �������ǰ����������Ϣ������������������� BSTree ����.
         //   ���� outFile Ϊ���Ŀ���ļ�
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

     private: //�����������Ʋ�������Ϊ˽�еģ�����ֹ Tnode ���󱻸���.
         Tnode(const Tnode&);    // �������������趨�壬��Ϊû��ʹ������������
         Tnode& operator=(const Tnode&);

     private:
         std::string word; // the text in this node
         int count;        // appear times of word in input
         Tnode* left;      // left  child
         Tnode* right;     // right child
}; // end of class Tnode


#endif // TNODE_HPP
