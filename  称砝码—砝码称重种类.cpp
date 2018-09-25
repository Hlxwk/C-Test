#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> weight(n);
        vector<int> num(n);
        for(int i=0;i<n;i++)
            cin>>weight[i];
        for(int i=0;i<n;i++)
            cin>>num[i];
        vector<int> ans;
        for(int i=0;i<=num[0];i++)
            ans.push_back(i*weight[0]);
        for(int j=1;j<n;j++)
        {
            int size=ans.size();
            for(int i=1;i<=num[j];i++)
                for(int m=0;m<size;m++)
                    if((find(ans.begin(),ans.end(),ans[m]+i*weight[j]))==ans.end())
                        ans.push_back(ans[m]+i*weight[j]);
        }
        cout<<ans.size()<<endl;
        
    }
    return 0;
}
