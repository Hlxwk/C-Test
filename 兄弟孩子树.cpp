 /*
兄弟孩子节点表示法
左节点——孩子
右节点——兄弟
1-2,3,4,5,6,7
4-8,
5-9,10
6-11,12,13
10-14,15
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct tree{
    int val;
    tree* left;
    tree* right;
    tree(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};
tree* search(tree* root,int value)//树查找
{
    if(root==NULL)return NULL;
    if(root->val==value)return root;
    if(root->right==NULL&&root->left==NULL)return NULL;
    else
    {
        if(root->left!=NULL)
        {
            tree* node=search(root->left,value);
            if(node!=NULL)return node;
            else return search(root->right,value);
        }
        else
        return search(root->right,value);
    }
}
void insert(tree* root,int a,int b)//树构建
{
    tree* node=search(root,a);
    if(node->left==NULL)
    {
        node->left=new tree(b);
    }
    else{
        tree* node1=node->left;
        while(node1->right!=NULL)node1=node1->right;
        node1->right=new tree(b);
    }
}
void preorder(tree* root)//先序遍历
{ 
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
vector<int> pretorder2(tree* root)//先序非递归
{
    Vector<int> res;
    if(!root)return res;
    Stack<tree*> s;
    S.push(root);
    if(!s.empty())
    {
     tree* p=s.top();
     res.push_back(s.top());
     S.pop();
     if(p->right)s.push(p->right);
     if(p->left)s.push(p->left);
    }
    Return res;
}

void inorder(tree* root)//中序遍历
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
vector<int> inorder2(tree* root)//中序非递归
{
    Vector<int> res;
    if(!root)return res;
    Stack<tree*> s;
    tree* p=root;
    while(root||!s.empty())
    {
     while(p)
     {
      s.push(p);
      p=p->left;
     } 
     if(!s.empty())
     {
      p=s.top();
      Res.push_back(p->val);
      s.pop();
      p=p->right;
     } 
    }
}
void postorder(tree* root)//后序遍历
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
vector<int> postorder2(tree* root)//后序非递归
{
    Vector<int> res;
    if(!root)return res;
    Stack<tree*> s;
    S.push(root);
    if(!s.empty())
    {
     tree* p=s.top();
     res.push_back(s.top());
     S.pop();
     if(p->left)s.push(p->left);
     if(p->right)s.push(p->right);
    }
    reverse(res.begin(),res.end());
    Return res;
}
vector<int> levelorder(tree* root)//层次遍历，可以获取树高和单层最多节点。
{
    vector<int> pr(2,0);
    vector<tree*> a;
    a.push_back(root);
    //cout<<a.size()<<endl;
    while(a.size()>=1)
    {
        //cout<<"1\n";
        pr[0]++;
        a.size()>pr[1]?pr[1]=a.size():1;
        vector<tree*> b=a;
        a.clear();
        for(int i=0;i<b.size();i++)
        {
            cout<<b[i]->val<<" ";
            if(b[i]->left!=NULL)a.push_back((b[i]->left));
            if(b[i]->right!=NULL)a.push_back((b[i]->right));
        }
    }
    return pr;
}
Int depth(tree* root)//树高
{
   if(!root)return 0;
   return(1+depth(root->left)>1+depth(root->right)?1+depth(root->left):1+depth(root->right));
}
int main()
{
    tree* root=new tree(1);//根节点
    insert(root,1,2);
    insert(root,1,3);
    insert(root,1,4);
    insert(root,1,5);
    insert(root,1,6);
    insert(root,1,7);
    insert(root,4,8);
    insert(root,5,9);
    insert(root,5,10);
    insert(root,6,11);
    insert(root,6,12);
    insert(root,6,13);
    insert(root,10,14);
    insert(root,10,15);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    vector<int> pr;
    pr=levelorder(root);
    cout<<endl;
    cout<<pr[0]<<" "<<pr[1]<<endl;
    return 0;

}