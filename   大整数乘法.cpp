#include <iostream>
#include <cmath>
using namespace std;
int Multiply(int u,int v,int n)
{
    if(v==0||u==0)return 0;
    else if(n==1)return u*v;
    else{
        int A=(int)u/pow(10,(int)(n/2));
        int B=u-A*pow(10,n/2);
        int C=(int)v/pow(10,(int)(n/2));
        int D=v-C*pow(10,(n/2));
        int AC=Multiply(A, C, n/2);
        int BD=Multiply(B, D, n/2);
        int ABCD=Multiply(A+B,C+D,n/2)-AC-BD;
        return AC*pow(10,n)+ABCD*pow(10,n/2)+BD;
        
    }
}
int main()
{
    int u,v,n;
    cin>>u>>v>>n;
    cout<<Multiply(u, v, n)<<endl;
}
