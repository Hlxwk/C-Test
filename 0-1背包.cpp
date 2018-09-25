#include <iostream>
using namespace std;
void zero_one(int W,int n,int V[][10],int v[],int w[],int b[][10])
{
    int i,we;
    for(i=0;we<=W;we++)V[i][we]=0;
    for(we=0;i<=n;i++)V[i][we]=0;
    for(i=1;i<=n;i++)
        for(we=1;we<=W;we++)
        {
            if(w[i]>we)
            {
                V[i][we]=V[i-1][we];
                b[i][we]=1;
            }
            else
            {
                if(V[i-1][we]>V[i-1][we-w[i]]+v[i])
                {
                    V[i][we]=V[i-1][we];
                    b[i][we]=1;
                }
                else{
                    V[i][we]=V[i-1][we-w[i]]+v[i];
                    b[i][we]=0;
                }
            }
        }
}
int main()
{
    int W=5,n=4;
    int V[10][10],v[]={0,12,10,20,15},w[]={0,2,1,3,2},b[10][10];
    zero_one(W, n, V, v, w, b);
    cout<<V[n][W]<<endl;
    return 0;
}
