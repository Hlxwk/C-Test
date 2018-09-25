//
//  main.cpp
//  test
//
//  Created by 韩文凯 on 2018/6/14.
//  Copyright © 2018年 韩文凯. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char,int> PAIR;
bool cmp_by_value(const PAIR& lhs,const PAIR& rhs)
{
    return lhs.second>rhs.second;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int i,a[1000]={0};
        for(i=0;i<n;i++)
        {
            string s;
            map<char,int> map1;
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                map1[s[j]]++;
            }
            vector<PAIR> map11(map1.begin(),map1.end());
            sort(map11.begin(), map11.end(), cmp_by_value);
            int m=26;
            for(int j=0;j!=map11.size();j++)
            {
                a[i]+=map11[j].second*m;
                m--;
            }
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<endl;
    }
    return 0;
}
