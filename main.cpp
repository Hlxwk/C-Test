#include<iostream>
using namespace std;
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    while(a||b||n)
    {
        int res[100]={0,1,1};
        for(int i=3;i<=49;i++)
        {
            res[i]=(a*res[i-1]+b*res[i-2])%7;
        }
        cout<<res[n%49]<<endl;
        cin>>a>>b>>n;
    }
    return 0;
}