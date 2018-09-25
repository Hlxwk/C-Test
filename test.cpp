#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    while(n||m)
    {
        vector<int> a;
        int tmp;
        for(int i=0;i<n;i++)
        cin>>tmp,a.push_back(tmp);
        a.push_back(m);
        stable_sort(a.begin(),a.end());
        for(auto it:a)cout<<it<<" ";
        cout<<a[a.size()-1]<<endl;
        cin>>n>>m;

    }
    return 0;
}
