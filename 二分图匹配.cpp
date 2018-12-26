//匈牙利算法求解二分图最大匹配问题
//列为左集合，行为右集合
#include<iostream>
#include<map>
using namespace std;
map<int,int> m1;//m1[end]=start;
map<int,int> m2;//m2[start]=end;
int graph[4][4]=
{
    1,1,0,0,
    0,1,1,0,
    1,1,0,0,
    0,0,1,0
};
int used[4]={0};
int girl[4]={-1,-1,-1,-1};
bool find1(int start)
{
    //cout<<"find "<<start<<endl;
    for(int end=0;end<4;end++)
    {
        if(graph[start][end]==1&&!used[end])
        {
            graph[start][end]=2;
            used[end]=1;
            m1[end]=start;
            for(int i=0;i<end;i++)
            if(graph[start][i]==2)graph[start][i]=3,used[i]=0;//调整边不可以重新当成1考虑
            return true;
        }
        else if(graph[start][end]==1&&used[end])
        {
            if(find1(m1[end]))
            {
                graph[start][end]=2;
                used[end]=1;
                m1[end]=start;
                for(int i=0;i<end;i++)
                if(graph[start][i]==2)graph[start][i]=3,used[i]=0;//调整边不可以重新当成1考虑
                return true;
            }
        }

    }
    return false;
}
bool find2(int start)
{
    for(int end=0;end<4;end++)
    {
        if(graph[start][end]&&!used[end])
        {
        used[end]=1;
        if(girl[end]==-1||find2(girl[end]))
        {
            girl[end]=start;
            return true;
        }
        }
    }
    return false;
}
int main()
{
    // for(int start=0;start<4;start++)
    // find1(start);
    // for(int start=0;start<4;start++)
    // for(int end=0;end<4;end++)
    // if(graph[start][end]==2)cout<<start<<" "<<end<<endl;
    int num=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)used[j]=0;
        if(find2(i))num++;
    }
    cout<<num<<endl;
    return 0;
}
