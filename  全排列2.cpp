#include <iostream>
using namespace std;
void perm2(int i,int n,int a[])
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<endl;
    }
    else{
        for(int j=0;j<n;j++)
        {
            if(!a[j])
            {
                a[j]=i+1;
                perm2(i+1, n, a);
                a[j]=0;
            }
        }
    }
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        a[i]=0;
    perm2(0, n, a);
    return 0;
}
