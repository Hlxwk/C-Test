#include <iostream>
using namespace std;
void fastway_func(int a1[],int a2[],int e[],int t1[],int t2[],int n,int f1[],int f2[])
{
    f1[1]=e[1]+a1[1];
    f2[1]=e[2]+a2[1];
    for(int i=2;i<=n;i++)
    {
        if(f1[i-1]+a1[i]<=f2[i-1]+t2[i-1]+a1[i])
            f1[i]=f1[i-1]+a1[i];
        else
            f1[i]=f2[i-1]+t2[i-1]+a1[i];
        if(f2[i-1]+a2[i]<=f1[i-1]+t1[i-1]+a2[i])
            f2[i]=f2[i-1]+a2[i];
        else
            f2[i]=f1[i-1]+t1[i-1]+a2[i];
    }
}
int main()
{
    int a1[7]={0,7,9,3,4,8,4};
    int a2[7]={0,8,5,6,4,5,7};
    int e[3]={0,2,4};
    int t1[6]={0,2,3,1,3,4};
    int t2[6]={0,2,1,2,2,1};
    int n=6;
    int f1[100],f2[100];
    fastway_func(a1, a2, e, t1, t2, n, f1, f2);
    for(int i=1;i<=6;i++)
        cout<<f1[i]<<" ";
    cout<<endl;
    for(int i=1;i<=6;i++)
        cout<<f2[i]<<" ";
    cout<<endl;
    return 0;
}
