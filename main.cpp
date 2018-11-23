#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool judge(vector<int>& a,vector<int>& b,int n)
{
    for(int i=0;i<n;i++)
    if(a[i]!=b[i])return false;
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> put(n),refer(n);
        for(int i=0;i<n;i++)
        cin>>put[i];
        for(int i=0;i<n;i++)
        cin>>refer[i];
        vector<int> tmp1=put;
        vector<int> tmp2=put;
        int flag=9999;
        for(int i=1;i<min(n,flag);++i)
        {
            int tmp=tmp1[i];
            int index=i;
            while(index>=0&&tmp1[index]>tmp)
            tmp1[index+1]=tmp1[index],--index;
            tmp1[++index]=tmp;
            if(judge(tmp1,refer,n))flag=i+2;
        }
    for(int i=0;i<n-1;++i)
    cout<<tmp1[i]<<" ";
    cout<<tmp1[n-1]<<endl;
    }
    return 0;
}
