#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
vector<int> a(3,0);
void perm(int m)
{
    if(m==0)copy(a.begin(),a.end(),ostream_iterator<int>(cout," ")),cout<<endl;
    for(int i=2;i>=0;--i)
    {
        if(!a[i])
        {
            a[i]=m;
            //cout<<a[i]<<endl;
            perm(m-1);
            a[i]=0;
        }
    }
}
int main()
{
    perm(3);
    return 0;
}