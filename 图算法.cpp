#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int graph[5][5]=//用于图的宽度深遍历
{
    0,1,0,1,0,
    1,0,1,1,0,
    0,1,0,0,1,
    1,1,1,0,0,
    0,0,1,0,0
};
int visited[5];//BFS
int visited2[5];//DFS
const int graph2[5][5]=//用于BellmanFord算法（权值有负）（单源点最短路径）
{
    0,6,0,7,0,
    0,0,5,8,-4,
    0,-2,0,0,0,
    0,0,-3,0,9,
    2,0,7,0,0
};
const int graph3[5][5]=//Dijkstra算法（正权值）
{
    0,10,0,5,0,
    0,0,1,2,0,
    0,0,0,0,4,
    0,3,9,0,2,
    7,0,6,0,0
};
int d[5],f[5];//路径和父亲节点
queue<int> node;//存储节点
void BFS(int i,int m)//宽度优先搜索(树的层次遍历)；
{
    visited[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int tmp=q.front();
        cout<<tmp<<" ";
        q.pop();
        for(int i=0;i<m;i++)
        {
            if(!visited[i]&&graph[tmp][i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
void DFS(int i,int m)//回溯法
{
    cout<<i<<" ";
    visited2[i]=1;
    for(int a=0;a<m;a++)
    {
        if(!visited2[a]&&graph[i][a])DFS(a, m);
    }
}
void DFS2(int i,int m)
{
    stack<int> s;
    s.push(i);
    cout<<i<<" ";
    visited2[i]=1;
    while(!s.empty())
    {
        int flag=1;
        for(int a=0;a<m;a++)
        {
            if(!visited2[a]&&graph[s.top()][a])
            {
                cout<<a<<" ";
                s.push(a);
                visited2[a]=1;
                flag=0;
                break;
            }
        }
        if(flag)s.pop();
    }

}
void Init_Single_Source(int s)//s为源点
{
    for(int i=0;i<5;i++)
    {
        d[i]=9999;
        f[i]=-1;
    }
    d[s]=0;
}
void Relax(int u,int v)
{
    if(d[v]>d[u]+graph2[u][v])
    d[v]=d[u]+graph2[u][v],f[v]=u,node.push(v);
    cout<<"d"<<v<<" ="<<d[v]<<endl;
}
bool BellmanFord(int s)
{
    Init_Single_Source(s);
    /*
    for(int n=0;n<4;n++)//算法最多n-1次，极限是最后节点需要遍历全部松弛
    {
        for(int i=0;i<5;i++)
        {
        for(int j=0;j<5;j++)
        {
            if(graph2[i][j])
            Relax(i,j);
        }
        cout<<"-----------\n";
        }
    }*/
    node.push(0);
    while(!node.empty())
    {
        int tmp=node.front();
        for(int i=0;i<5;i++)
        {
            if(graph2[tmp][i])
            {
                Relax(tmp,i);
            }
        }
        node.pop();
    }
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    {
    if(graph2[i][j])
    {
        if(d[j]>d[i]+graph2[i][j])
        {
            return false;//负权回路
        }
    }
    }
    return true;
}void Relax2(int u,int v)
{
    if(d[v]>d[u]+graph2[u][v])
    d[v]=d[u]+graph3[u][v],f[v]=u,node.push(v);
    cout<<"d"<<v<<" ="<<d[v]<<endl;
}
void Dijkstra(int s)
{
    Init_Single_Source(s);
    int flag[5]={0};
    for(int i=0;i<5;i++)
    {
        int min_value=99999,min_flag=-1;
        for(int i=0;i<5;i++)
        {
            if(!flag[i]&&d[i]<min_value)min_value=d[i],min_flag=i;
        }
        flag[min_flag]=1;
        for(int j=0;j<5;j++)
        if(graph3[min_flag][j])
        Relax2(min_flag,j);
    }
}
int main()
{
    BFS(0, 5);
    cout<<endl;
    // DFS(0,5);
    // cout<<endl;
    DFS2(0,5);
    cout<<endl;    
    // // if(BellmanFord(0))
    // // {
    // //     for(int i=0;i<5;i++)
    // //     cout<<d[i]<<" ";
    // // }
    // //cout<<"false!";
    // cout<<endl;
    // Dijkstra(0);
    // for(int i=0;i<5;i++)
    // cout<<d[i]<<" ";
    // cout<<endl;
    return 0;
}
