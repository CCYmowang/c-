//文件摘要：实现了二叉树的结点类型 Tode
//17130130312 曹晨瑶
//2019.5.25
#include"Tnode.hpp"
#include<string>

using namespace std;

Tnode::Tnode(const char* str)
    : word(NULL == str ? "" : str), count(1),
      left(NULL), right(NULL)
    //成员初始化列表
{
}

Tnode::Tnode(const string& str)
{
     word = str;  // 将 word 的值从 初始的空串 修改为 str 相同的值
     count = 1;   // 将 count 的值从 初始的随机值 修改为 1
     left = right = NULL;
}

Tnode::~Tnode()
{
   /*
     if(NULL != left )  // 递归地释放左子树
         delete left ;  // call Tnode::~Tnode()

     if(NULL != right ) //递归地释放右子树
         delete right ; // call Tnode::~Tnode()
   */
}
