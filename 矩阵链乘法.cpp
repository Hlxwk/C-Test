#include <iostream>
using namespace std;
void DP_Matrixchain(int p[],int m[][10],int n,int s[][10])
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++)//l,矩阵链长度:2->n;
    {
        for(int i=1;i<=n-l+1;i++)//i指向矩阵链长度起始
        {
            int j=i+l-1;//j指向矩阵链长度末尾
            m[i][j]=99999;
            for(int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void PrintChain(int s[][10],int i,int j)
{
    if(i==j)cout<<"A"<<i;
    else{
        cout<<"(";
        PrintChain(s, i, s[i][j]);
        PrintChain(s, s[i][j]+1, j);
        cout<<")";
    }
}
int main()
{
    int p[]={30,35,15,5,10,20,25};
    int m[10][10],s[10][10];
    DP_Matrixchain(p, m, 6,s);
    cout<<m[1][6]<<endl;
    PrintChain(s, 1, 6);
    return 0;
}
