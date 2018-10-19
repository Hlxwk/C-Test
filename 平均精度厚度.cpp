#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"请输入区域个数： ";
    int n,sum_area=0;
    cin>>n;
    vector<int> area;
    cout<<"请输入各个区域长和宽：";
    for(int i=0;i<n;i++)
    {
        int l,d;
        cin>>l>>d;
        area.push_back(l*d);
        sum_area+=l*d;
    }
    cout<<"请输入各个区域平均精度和厚度： ";
    double x=0,y=0;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        x+=((double)area[i]/(double)sum_area)*a;
        y+=((double)area[i]/(double)sum_area)*b;
    }
    cout<<"加权平均精度为： "<<x<<endl
        <<"加权平均厚度为： "<<y<<endl;
    return 0;
}