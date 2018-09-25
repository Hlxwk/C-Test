#include <iostream>
#include<cstring>
using namespace std;
int maxsub(int a[],int n)
{
    int b=0,max=-9999;
    for(int i=0;i<n;i++)
    {
        if(b>0)
            b+=a[i];
        else
            b=a[i];
        if(b>max)max=b;
    }
    return max;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a[101][101];
        int array[101],max1=-9999,max2=-9999;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        for(int i=0;i<n;i++)
        {
            memset(array,0,sizeof(array));
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    array[k]+=a[j][k];
                max1=maxsub(array,n);
                if(max1>max2)max2=max1;
            }
        }
        cout<<max2<<endl;



    }
    return 0;
}
