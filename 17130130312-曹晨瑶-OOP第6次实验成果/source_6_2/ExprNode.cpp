//文件摘要：定义了表达式语法树及其所有结点类型的实现。
//17130130312 曹晨瑶
//2018.6.18

#include <iostream>
#include <string>
#include "ExprNode_d.hpp"
using namespace std;

//生成表达式的后缀式.祖先类只输出结点自己的后缀式，子树的后缀式由其派生类来实现
void basic_node::generatePostfix(string& retValue) const
{
    retValue += mToken.tok_txt+" ";
}
//生成表达式的前缀式.祖先类只输出结点自己的前缀式，子树的前缀式由其派生类来实现
void basic_node::generatePrefix(string& retValue) const
{
    retValue += mToken.tok_txt+" ";

}
//生成表达式的中缀式.祖先类只输出结点自己的中缀式，子树的中缀式由其派生类来实现
void basic_node::generateInfix(string& retValue) const
{
    retValue += mToken.tok_txt;
}
//祖先类仅输出结点自己的信息，子树的输出由派生类来实现
void basic_node::printTree(ostream& outDevice,int deepth) const
{
    for(;deepth>0;--deepth)//向右缩进的空白字符
        cout<<" ";
    //输出当前记号文本信息、记号在原表达式中的位置、当前结点的类名
    outDevice<<mToken.tok_txt<<"\t\t"<<mToken.tok_pos<<"\t"<<typeName()<<endl;
}
//二元操作的实现
CBinaryOpNode::~CBinaryOpNode()//二元操作数的析构函数
{
    //将左右子树销毁
    if(mLeftChild!=NULL)
        delete mLeftChild;
    if(mRightChild!=NULL)
        delete mRightChild;
}
//生成子表达式的后缀式并返回.
void CBinaryOpNode::generatePostfix(string& retValue) const
{
    mLeftChild->generatePostfix(retValue);// 左孩子生成自己的后缀式
    mRightChild->generatePostfix(retValue);// 右孩子生成自己的后缀式
    basic_node::generatePostfix(retValue);// 最后拼接上操作符自身
}
// 生成子表达式的前缀式并返回
 void  CBinaryOpNode::generatePrefix(std::string & retValue) const
 {
     basic_node::generatePrefix(retValue);  // 首先拼接操作符自身
     mLeftChild->generatePrefix(retValue);  // 左孩子生成自己的前缀式
     mRightChild->generatePrefix(retValue); // 右孩子生成自己的前缀式
 }
 // 生成子表达式的中缀式并返回
 void  CBinaryOpNode::generateInfix(std::string & retValue) const
 {
     retValue += "(";
     mLeftChild->generateInfix(retValue);  // 左孩子生成自己的中缀式
     if(retValue[retValue.length()-1]!=' ')//若末尾没有空格，则补空格
        retValue += " ";
     retValue += mToken.tok_txt +" ";
     mRightChild->generateInfix(retValue); // 右孩子生成自己的中缀式
     retValue += ")";
 }
//打印树。先序遍历
void CBinaryOpNode::printTree(std::ostream& outDevice, int deepth) const
{
    basic_node::printTree(outDevice,deepth);//输出结点自身信息
    mLeftChild->printTree(outDevice,deepth+1);//输出左子树的信息
    mRightChild->printTree(outDevice,deepth+1);//输出右子树的信息
}

// 一元操作的实现
CUnaryOpNode::~CUnaryOpNode()
{
    if(mChild!=NULL)//递归地销毁子树
        delete mChild;
}
// 产生子表达式的后缀式并返回
void CUnaryOpNode::generatePostfix(string& retValue) const
{
    mChild->generatePostfix(retValue);// 孩子生成自己的后缀式
    basic_node::generatePostfix(retValue);// 追加上操作符自身
}
// 产生子表达式的前缀式并返回
 void  CUnaryOpNode::generatePrefix(std::string & retValue) const
 {
     basic_node::generatePrefix(retValue); // 先追加操作符自身
     mChild->generatePrefix(retValue); // 孩子生成自己的前缀式
 }
// 产生子表达式的中缀式并返回。
 void  CUnaryOpNode::generateInfix(std::string & retValue) const
 {
     retValue += "( ";
     basic_node::generateInfix(retValue); // 拼上操作符自身
     mChild->generateInfix(retValue); // 孩子生成自己的中缀式
     if( retValue[retValue.length()-1] != ' ') // 若末尾没有空格，则添加一个。
         retValue += " )";
     else
         retValue += ")";
 }
 //打印树。先序遍历
void CUnaryOpNode::printTree(std::ostream& outDevice, int deepth) const
{
    basic_node::printTree(outDevice,deepth);//输出结点自身信息
    mChild->printTree(outDevice,deepth+1);//输出子树的信息
}
