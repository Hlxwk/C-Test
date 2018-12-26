#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};
ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* p=NULL;
        while(head)
        {
            ListNode* tmp=new ListNode(head->val);
            tmp->next=p;
            p=tmp;
            head=head->next;
        }
        return p;
    }
int main()
{
    ListNode* head=new ListNode(1);
    ListNode* p=head;
    int i=2;
    while(i<=5)
    {
        ListNode* tmp=new ListNode(i++);
        p->next=tmp;
        p=p->next;
    }
    p->next=NULL;
    p=head;
    p=reverseList(head);
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}