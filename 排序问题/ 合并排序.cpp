#include <iostream>
using namespace std;
void Merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q-1+1;
    int L[100],R[100];
    for(int i=0;i<n1;i++)
        L[i]=a[p+i];
    for(int i=0;i<n2;i++)
        R[i]=a[q+1+i];
    L[n1]=9999;
    R[n2]=9999;// be sure for inserting in a;
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])a[k]=L[i++];
        else a[k]=R[j++];
    }
}
void Mergesort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=(r+p)/2;
        Mergesort(a, p, q);
        Mergesort(a, q+1, r);
        Merge(a,p,q,r);
        
    }
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    Mergesort(a, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
