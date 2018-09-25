/*
首先，快速幂的目的就是做到快速求幂，假设我们要求a^b,按照朴素算法就是把a连乘b次，
这样一来时间复杂度是O(b)也即是O(n)级别，快速幂能做到O(logn)，快了好多好多。它的原理如下：
假设我们要求a^b，那么其实b是可以拆成二进制的，该二进制数第i位的权为2^(i-1)，例如当b==11时
　　　　　　　　　　　　　　　　　　　　　　a11=a(2^0+2^1+2^3)
11的二进制是1011，11 = 2³×1 + 2²×0 + 2¹×1 + 2º×1，
因此，我们将a¹¹转化为算 a2^0*a2^1*a2^3，也就是a1*a2*a8 ，
看出来快的多了吧原来算11次，现在算三次，  
*/
#include<iostream>
using namespace std;
int quick_pow(int a,int b)
{
    int ans=1,base=a;
    while(b!=0)
    {
        if(b&1==1)
        ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<quick_pow(a,b)<<endl;
    }
    return 0;
}