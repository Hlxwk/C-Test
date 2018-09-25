#include<iostream>
using namespace std;
struct node1
{
    int key_number;
    node1* next;
    node1(int a)
    {
        key_number=a;
        next=NULL;
    }
};
int main()
{
    int n;
    while(cin>>n)
    {
        int val;
        node1* head= new node1(0);
        node1* p =head;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            node1* q= new node1(val);
            p->next=q;
            p=q;
        }
        int k;
        cin>>k;
        node1* temp = head;
        for(int i=0;i<n-k+1;i++)
        temp=temp->next;
        cout<<temp->key_number<<endl;
    } 
}