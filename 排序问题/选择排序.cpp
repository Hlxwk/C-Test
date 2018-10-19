#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a[100];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n-1;i++)
        {
            int min_index=i,j;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    min_index=j;
                }
            }
            swap(a[i],a[min_index]);
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
//递归解法
#include<iostream>
#include<algorithm>
using namespace std;
void select_sort(int i,int n,int* a)
{
    if(i==n)return ;
    else{
        int flag=i,value=*(a+i);
        for(int j=i+1;j<n;++j)
          *(a+j)<value?(value=*(a+j))&&(flag=j):1;
        swap(*(a+i),*(a+flag));
        select_sort(i+1,n,a);
    }
}
int main()
{
    int a[]={5,4,3,2,1};
    select_sort(0,5,a);
    for(int i=0;i<5;i++)
    cout<<a[i]<<endl;
    return 0;
}
