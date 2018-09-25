#include<iostream>
#include <algorithm>
using namespace std;
void perm(int i,int n,int a[])
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            swap(a[j], a[i]);
            perm(i+1,n,a);
            swap(a[j],a[i]);
        }
    }
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
        a[i]=i+1;
    perm(0, n, a);
    return 0;
    
}
