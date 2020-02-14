//�ļ�ժҪ��ʵ��������������� BSTree
//17130130312 �ܳ���
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
    if(newWord.length() == 0) // ���Կմ�
        return false;
    regist_word(Root, newWord); // ���ø������������ı��������е��ʵ�λ��
    return true;
}

bool BSTree::regist(const char* newWord)
{
    if(NULL == newWord || '\0' == newWord[0])  // ���Կմ�
        return false;

    regist_word(Root, newWord);
    return true;
}

int BSTree::regist_word(Tnode* & root, const string& newWord)
{
     // �� root Ϊ��(��)�����򴴽�����㲢���ظ������ߡ�
     // ��ʱ��newWord �϶��������е����ϣ��ҵ����ߣ����¿������Ѿ��ҵ���
     // ��������λ�ã������������������㲢���ظ������ߡ�
     if(NULL == root)
     {
         //���ﶯ̬�����Ľ����󣬻����������� �Զ� delete �ͷ�.
         root = new Tnode( newWord );
         return 0;
     }

 // ������Ϊ�գ������Ҫ�����λ�ã���׷���½�㣨Ҷ�ӽ�㣩.
 // (���ﰴ������������֯)

     // string.compare() �ȼ���
     //   strcmp( newWord.c_str(), root->getWord().c_str() )
     int r = newWord.compare(root->getWord());
     if( r == 0 ) // newWord �� root->getWord() ���洢���ַ�����ͬ
     {
         // newWord �Ѿ��Ǽ������У�����������.
         root->getCount() += 1;
     }
     else if ( r < 0 ) // Сֵ�ŵ� ����( newWord < root->getWord())
     {
         regist_word(root->getLeft(), newWord); // �ݹ���ú�������
     }
     else    // ��ֵ�ŵ� �Һ���
     {
         regist_word(root->getRight(), newWord); // �ݹ���ú�������
     }

     return 0;
}

void BSTree::print_pre_order(const Tnode* root,unsigned int indent){
    //��ӡ��Ϣ indent�������
    if(!root)
        return;
    for(unsigned int k=0;k<indent;k++)
        cout <<" ";
    cout << root->getWord() << ": " << root->getCount()<<" "<<endl;//��ӡ���ɿո���������
    if(root == NULL)
        return;
    print_pre_order(root->getLeft(), indent+1);//�ݹ���ã���ӡ������
    if(root->getLeft()&&!root->getRight()){
        for(unsigned k=0;k<indent;k++)
            cout<<" ";
        cout<<"<NULL>"<<endl;
        return;
    }
    print_pre_order(root->getRight(), indent+1);//�ݹ���ã���ӡ������
}

void BSTree::print_middle_order(const Tnode* root)
{
    //����ĸ��˳�����
    if(root==NULL)
        return;
    print_middle_order(root->getLeft());
    cout<<root->getWord()<<": "<<root->getCount()<<' '<<endl;
    print_middle_order(root->getRight());
}



bool BSTree::deleteBST(Tnode* root){
    //������
    if(root==NULL){
        return false;
    }
    deleteBST(root->getLeft());
    deleteBST(root->getRight());
    delete root;
    return true;
}

