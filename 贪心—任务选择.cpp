#include<iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
vector<string> res;
void GreedyTaskSelect(int s[],int f[],int n)
{
    res.push_back("a1");
    int i=1;
    for(int m=2;m<=n;++m)
    {
        if(s[m]>=f[i])
        {
            string tmp;
            stringstream ss;
            ss<<'a'<<m;
            ss>>tmp;
            res.push_back(tmp);
            i=m;
        }
    }
}
int main()
{
    int s[12]={0,1,3,0,5,3,5,6,8,8,2,12},
    f[12]={0,4,5,6,7,8,9,10,11,12,13,14};
    GreedyTaskSelect(s, f, 11);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
