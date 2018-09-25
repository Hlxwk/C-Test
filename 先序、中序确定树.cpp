/*
根据preorder和inorder确定唯一一棵二叉树，
并求解postorder
preorder：123456
indorder：324165
postorder：342651
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct tree 
{
    char data;
    tree* right;
    tree* left;
};
void create_tree(tree* &root,string& preorder,string& inorder)//传入指针引用或者指针的指针
{
    if(preorder.size()==0)
    {
        root=NULL;
        return;
    }
    char rootnode=preorder[0];
    //cout<<rootnode<<endl;
    int index=inorder.find(rootnode);
    string lchild_inorder=inorder.substr(0,index);
    string rchild_inorder=inorder.substr(index+1);
    int lchild_length=lchild_inorder.size();
    int rchild_length=rchild_inorder.size();
    string lchild_preorder=preorder.substr(1,lchild_length);
    string rchild_preorder=preorder.substr(1+lchild_length);
    root=new tree;//出现问题，不能修改指针的地址，要修改指针的内容。
    if(root!=NULL)
    {
        root->data=rootnode;
        create_tree(root->left,lchild_preorder,lchild_inorder);
        create_tree(root->right,rchild_preorder,rchild_inorder);
    }
}
void postorder(tree* root)
{
    //cout<<"1"<<endl;
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    tree* root;
    string preorder="123456";
    string inorder="324165";
    create_tree(root,preorder,inorder);
    postorder(root);
    cout<<endl;
    return 0;
}