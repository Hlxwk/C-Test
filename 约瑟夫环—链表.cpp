#include<iostream>
struct linknode
{
    int num;
    linknode* next;
    linknode(int n)
    {
        num=n;
        next=NULL;
    };
};
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        linknode* head=new linknode(1);
        linknode* p=head;
        for(int i=2;i<=n;i++)
        {
            linknode* temp=new linknode(i);
            p->next=temp;
            p=p->next;
        }
        p->next=head;
        p=head;
        int die=0;
        while(die<n-1)
        {
            int i=0;
            linknode* q=p;
            while(i<m-2)
            {
                q=q->next;
                i++;
            }
            linknode* m=q;
            q=q->next;
            m->next=q->next;
            die++;
            p=m->next;
        }
        cout<<p->num<<endl;
    }
    return 0;
}