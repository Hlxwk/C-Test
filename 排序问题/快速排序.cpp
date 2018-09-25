#include <iostream>
#include <algorithm>
using namespace std;
int partition(int a[],int left,int right)
{
    int key=a[right];
    while(left<right)
    {
        while(left<right&&a[left]<=key)
            ++left;
        if(left<right)a[right]=a[left];
        while(left<right&&a[right]>=key)
            --right;
        if(left<right)a[left]=a[right];
    }
    a[left]=key;
    return left;
}
void quick_sort(int a[],int left,int right)
{
    if(left<right)
    {
        int q=partition(a, left, right);
        quick_sort(a, left, q-1);
        quick_sort(a, q+1, right);
    }
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
