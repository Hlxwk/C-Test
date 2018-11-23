#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
void merge(vector<int>& A,int left,int middle,int right)
{
    vector<int> tmp1;
    tmp1.insert(tmp1.begin(),A.begin()+left,A.begin()+middle+1);
    vector<int> tmp2;
    tmp2.insert(tmp2.begin(),A.begin()+middle+1,A.begin()+right+1);
    tmp1.push_back(9999);
    tmp2.push_back(9999);
    int i=0,j=0;
    int m=left;
    while(i<tmp1.size()-1||j<tmp2.size()-1)
    {
        if(tmp1[i]<=tmp2[j])
        A[m]=tmp1[i++];
        else
        A[m]=tmp2[j++];
        m++;
    }
}
void merge_sort(vector<int>& A,int left,int right)
{
    if(left<right)
    {
        int p=(right+left)/2;
        merge_sort(A,left,p);
        merge_sort(A,p+1,right);
        merge(A,left,p,right);
    }
}
int main()
{
    int a[]={9,8,7,6,5,4,3,2,1};
    vector<int> A(a,a+9);
    merge_sort(A,0,8);
    copy(A.begin(),A.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
}