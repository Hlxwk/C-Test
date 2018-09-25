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
