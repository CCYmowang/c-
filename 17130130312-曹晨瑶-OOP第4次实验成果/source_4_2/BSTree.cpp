//文件摘要：实现排序二叉树类型 BSTree
//17130130312 曹晨瑶
//2019.5.25
#include"Tnode.hpp"
#include"BSTree.hpp"
#include<string>

using namespace std;


BSTree::BSTree() : Root(NULL)
{
}

BSTree::~BSTree()
{
    destroy();
}

void BSTree::destroy()
{
    deleteBST(Root);
    Root = NULL;
}

bool BSTree::regist(const string& newWord)
{
    if(newWord.length() == 0) // 忽略空串
        return false;
    regist_word(Root, newWord); // 调用辅助函数，将文本放在树中的适当位置
    return true;
}

bool BSTree::regist(const char* newWord)
{
    if(NULL == newWord || '\0' == newWord[0])  // 忽略空串
        return false;

    regist_word(Root, newWord);
    return true;
}

int BSTree::regist_word(Tnode* & root, const string& newWord)
{
     // 若 root 为空(子)树，则创建根结点并返回给调用者。
     // 此时，newWord 肯定不在已有的树上，且调用者（向下看看）已经找到了
     // 所需插入的位置，所以这里生成所需结点并返回给调用者。
     if(NULL == root)
     {
         //这里动态创建的结点对象，会由析构函数 自动 delete 释放.
         root = new Tnode( newWord );
         return 0;
     }

 // 若树不为空，则查找要插入的位置，并追加新结点（叶子结点）.
 // (这里按二叉排序树组织)

     // string.compare() 等价于
     //   strcmp( newWord.c_str(), root->getWord().c_str() )
     int r = newWord.compare(root->getWord());
     if( r == 0 ) // newWord 和 root->getWord() 所存储的字符串相同
     {
         // newWord 已经登记在树中，就是这个结点.
         root->getCount() += 1;
     }
     else if ( r < 0 ) // 小值放到 左孩子( newWord < root->getWord())
     {
         regist_word(root->getLeft(), newWord); // 递归调用函数自身
     }
     else    // 大值放到 右孩子
     {
         regist_word(root->getRight(), newWord); // 递归调用函数自身
     }

     return 0;
}

void BSTree::print_pre_order(const Tnode* root,unsigned int indent){
    //打印信息 indent树的深度
    if(!root)
        return;
    for(unsigned int k=0;k<indent;k++)
        cout <<" ";
    cout << root->getWord() << ": " << root->getCount()<<" "<<endl;//打印若干空格，向右缩进
    if(root == NULL)
        return;
    print_pre_order(root->getLeft(), indent+1);//递归调用；打印左子树
    if(root->getLeft()&&!root->getRight()){
        for(unsigned k=0;k<indent;k++)
            cout<<" ";
        cout<<"<NULL>"<<endl;
        return;
    }
    print_pre_order(root->getRight(), indent+1);//递归调用；打印右子树
}

void BSTree::print_middle_order(const Tnode* root)
{
    //按字母表顺序输出
    if(root==NULL)
        return;
    print_middle_order(root->getLeft());
    cout<<root->getWord()<<": "<<root->getCount()<<' '<<endl;
    print_middle_order(root->getRight());
}



bool BSTree::deleteBST(Tnode* root){
    //销毁树
    if(root==NULL){
        return false;
    }
    deleteBST(root->getLeft());
    deleteBST(root->getRight());
    delete root;
    return true;
}

