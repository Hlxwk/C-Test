#include <iostream>//分支限界算法
#include <vector>
#include <queue>
#include <iterator>
using namespace std;
struct node 
{
    int index;
    int weight;
    int lchild;
    int parent;
};
struct node1
{
  
    int weight;
    bool operator < (const node1 &a)
    {
        return weight<a.weight;
    }
};


queue<node> q;
priority_queue<node1> q2;
node node1[20];
vector<int> bestx(10);
void SaveQueue(int wt,int i,int j,int n,int& bestw,int pre,int& bestE,int ch)
{
    if(i==n-1)
    {
        if(wt>bestw)
        {
            // cout<<"jiji"<<endl;
            // cout<<"bestnode"<<pre<<endl;
            bestw=wt;
            bestE=pre;
            bestx[n-1]=ch;
            //cout<<ch<<endl;
        }
    }
    else
    {
        node1[j].weight=wt;
        node1[j].lchild=ch;
        node1[j].parent=pre;
        node1[j].index=j;
        q.push(node1[j]);
        cout<<"node"<<j<<" "<<wt<<" parent "<<node1[j].parent<<" lchild "<<ch<<endl;
    }
}
int FIFO_Max_Loading(vector<int>& w, int W, int n)
{
    node1[0].weight=-1;
    int pre=0,bestE;
    int i=0,j=1;
    q.push(node1[0]);
    int cw=0,bestw=0,r=0;
    for(int i=1;i<n;++i)r+=w[i];
    while(!q.empty())
    {
        if(cw+w[i]<=W)
        {
            //if(cw+w[i]>bestw)bestw=cw+w[i];
            //if(i<n)q.push(cw+w[i]);
            SaveQueue(cw+w[i],i,j,n,bestw,pre,bestE,1);
            j++;
        }
        if(cw+r>bestw)SaveQueue(cw,i,j,n,bestw,pre,bestE,0),j++;
        node tmp;
        tmp=q.front();
        q.pop();
        if(tmp.weight==-1)
        {
            if(q.empty())goto L;
            q.push(node1[0]);
            tmp=q.front();
            q.pop();
            i++;//控制层数
            r-=w[i];
        }
        cw=tmp.weight;
        pre=tmp.index;
    }
    L:
    for(int a=n-2;a>=0;a--)
    {
        bestx[a]=node1[bestE].lchild;
        bestE=node1[bestE].parent;
    }
    return bestw;
}
int main()
{
    int a[]={8,6,2};
    int W=12;
    vector<int> w(a,a+3);
    int bestw=FIFO_Max_Loading(w,W,3);
    cout<<bestw<<endl;
    copy(bestx.begin(),bestx.end(),ostream_iterator<int>(cout," "));
    //cout<<endl;
    return 0;
}