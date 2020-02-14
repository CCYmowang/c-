//�ļ�ժҪ�������˱��ʽ�﷨���������н�����͵�ʵ�֡�
//17130130312 �ܳ���
//2018.6.18

#include <iostream>
#include <string>
#include "ExprNode_d.hpp"
using namespace std;

//���ɱ��ʽ�ĺ�׺ʽ.������ֻ�������Լ��ĺ�׺ʽ�������ĺ�׺ʽ������������ʵ��
void basic_node::generatePostfix(string& retValue) const
{
    retValue += mToken.tok_txt+" ";
}
//���ɱ��ʽ��ǰ׺ʽ.������ֻ�������Լ���ǰ׺ʽ��������ǰ׺ʽ������������ʵ��
void basic_node::generatePrefix(string& retValue) const
{
    retValue += mToken.tok_txt+" ";

}
//���ɱ��ʽ����׺ʽ.������ֻ�������Լ�����׺ʽ����������׺ʽ������������ʵ��
void basic_node::generateInfix(string& retValue) const
{
    retValue += mToken.tok_txt;
}
//��������������Լ�����Ϣ���������������������ʵ��
void basic_node::printTree(ostream& outDevice,int deepth) const
{
    for(;deepth>0;--deepth)//���������Ŀհ��ַ�
        cout<<" ";
    //�����ǰ�Ǻ��ı���Ϣ���Ǻ���ԭ���ʽ�е�λ�á���ǰ��������
    outDevice<<mToken.tok_txt<<"\t\t"<<mToken.tok_pos<<"\t"<<typeName()<<endl;
}
//��Ԫ������ʵ��
CBinaryOpNode::~CBinaryOpNode()//��Ԫ����������������
{
    //��������������
    if(mLeftChild!=NULL)
        delete mLeftChild;
    if(mRightChild!=NULL)
        delete mRightChild;
}
//�����ӱ��ʽ�ĺ�׺ʽ������.
void CBinaryOpNode::generatePostfix(string& retValue) const
{
    mLeftChild->generatePostfix(retValue);// ���������Լ��ĺ�׺ʽ
    mRightChild->generatePostfix(retValue);// �Һ��������Լ��ĺ�׺ʽ
    basic_node::generatePostfix(retValue);// ���ƴ���ϲ���������
}
// �����ӱ��ʽ��ǰ׺ʽ������
 void  CBinaryOpNode::generatePrefix(std::string & retValue) const
 {
     basic_node::generatePrefix(retValue);  // ����ƴ�Ӳ���������
     mLeftChild->generatePrefix(retValue);  // ���������Լ���ǰ׺ʽ
     mRightChild->generatePrefix(retValue); // �Һ��������Լ���ǰ׺ʽ
 }
 // �����ӱ��ʽ����׺ʽ������
 void  CBinaryOpNode::generateInfix(std::string & retValue) const
 {
     retValue += "(";
     mLeftChild->generateInfix(retValue);  // ���������Լ�����׺ʽ
     if(retValue[retValue.length()-1]!=' ')//��ĩβû�пո��򲹿ո�
        retValue += " ";
     retValue += mToken.tok_txt +" ";
     mRightChild->generateInfix(retValue); // �Һ��������Լ�����׺ʽ
     retValue += ")";
 }
//��ӡ�����������
void CBinaryOpNode::printTree(std::ostream& outDevice, int deepth) const
{
    basic_node::printTree(outDevice,deepth);//������������Ϣ
    mLeftChild->printTree(outDevice,deepth+1);//�������������Ϣ
    mRightChild->printTree(outDevice,deepth+1);//�������������Ϣ
}

// һԪ������ʵ��
CUnaryOpNode::~CUnaryOpNode()
{
    if(mChild!=NULL)//�ݹ����������
        delete mChild;
}
// �����ӱ��ʽ�ĺ�׺ʽ������
void CUnaryOpNode::generatePostfix(string& retValue) const
{
    mChild->generatePostfix(retValue);// ���������Լ��ĺ�׺ʽ
    basic_node::generatePostfix(retValue);// ׷���ϲ���������
}
// �����ӱ��ʽ��ǰ׺ʽ������
 void  CUnaryOpNode::generatePrefix(std::string & retValue) const
 {
     basic_node::generatePrefix(retValue); // ��׷�Ӳ���������
     mChild->generatePrefix(retValue); // ���������Լ���ǰ׺ʽ
 }
// �����ӱ��ʽ����׺ʽ�����ء�
 void  CUnaryOpNode::generateInfix(std::string & retValue) const
 {
     retValue += "( ";
     basic_node::generateInfix(retValue); // ƴ�ϲ���������
     mChild->generateInfix(retValue); // ���������Լ�����׺ʽ
     if( retValue[retValue.length()-1] != ' ') // ��ĩβû�пո������һ����
         retValue += " )";
     else
         retValue += ")";
 }
 //��ӡ�����������
void CUnaryOpNode::printTree(std::ostream& outDevice, int deepth) const
{
    basic_node::printTree(outDevice,deepth);//������������Ϣ
    mChild->printTree(outDevice,deepth+1);//�����������Ϣ
}
