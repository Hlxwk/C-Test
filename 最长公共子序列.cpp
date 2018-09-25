#include <iostream>
#include <algorithm>
using namespace std;
void DPLCSLenrht(char x[],char y[],int m,int n,int c[][10],int b[][10])
{
    for(int i=1;i<=m;i++)c[i][0]=0;
    for(int i=0;i<=n;i++)c[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
                c[i][j]=c[i-1][j-1]+1,b[i][j]=1;
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j],b[i][j]=0;
            else
                c[i][j]=c[i][j-1],b[i][j]=2;
        }
    }
}
void PrintLCS(int b[][10],char x[],int i,int j)
{
    if(b[i][j]==1)
    {
        PrintLCS(b, x, i-1, j-1);
        cout<<x[i]<<endl;
    }
    else if(b[i][j]==0)
        PrintLCS(b, x, i-1, j);
    else if(b[i][j]==2)
        PrintLCS(b, x, i, j-1);
}
int main()
{
    char x[] {'0','b','d','c','a','b','a'};
    char y[] {'0','a','b','c','b','d','a','b'};
    int c[10][10],b[10][10];
    DPLCSLenrht(x, y, 6, 7, c,b);
    cout<<c[6][7]<<endl;
    PrintLCS(b, x, 6, 7);
}
