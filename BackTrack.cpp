//回溯算法
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
int bestw=0;
void BackTrackPerm(int i,int n,vector<int>& perm)//全排列回溯
{
   if(i >= n)
        copy(perm.begin(),perm.end(),ostream_iterator<int>(cout," ")),
        std::cout<<endl;
   else
      {
        for(int j=i;j<n;++j)
          {
              swap(perm[i],perm[j]);
              BackTrackPerm(i+1,n,perm);
              swap(perm[i],perm[j]);
          }
      }
}
void BackTrackLoading(int i,int n,int cw,int& W,vector<int>& w,int& R,vector<int>& x)//装载问题
{
  if(i >= n)
  {
    if(cw>bestw)
        bestw=cw,
        std::cout<<bestw<<endl;
        copy(x.begin(),x.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
  }
  else
  {
     R-=w[i];
     if(cw+w[i]<=W)
     {
        x[i]=1;
        cw+=w[i];
        BackTrackLoading(i+1,n,cw,W,w,R,x);
        cw-=w[i];
     }
     if(R+cw>bestw)
     x[i]=0,
     BackTrackLoading(i+1,n,cw,W,w,R,x);
     R+=w[i];
  }
}
bool Nqueen_Place(int k,vector<int>& x)
{
  for(int i=0;i<k;i++)
  if(abs(x[k]-x[i])==abs(k-i)||x[k]==x[i])
  return false;
  return true;
}
void BackTrackNqueen(int i,int n,vector<int>& x)//N皇后问题
{
  if(i>=n)
  copy(x.begin(),x.end(),ostream_iterator<int>(cout," ")),
  cout<<endl;
  else
  {
    for(int j=0;j<n;j++)
    {
      x[i]=j;
      if(Nqueen_Place(i,x))
      BackTrackNqueen(i+1,n,x);
    }
  }
}
void BackTrackSubset(int i,int n,vector<vector<int> >& res,vector<int>& x,vector<int>& flag)
{
  res.push_back(x);
  if(i==n)return;
  else
  {
    for(int j=i;j<n;j++)
    {
      //if(!flag[j])
      {
        //flag[j]=1;
      x.push_back(j);
      BackTrackSubset(j+1,n,res,x,flag);
      x.pop_back();
      //flag[j]=0;
      }
    }
  }
}
int main()
{
/*
  int a[]={1,2,3};
  vector<int> perm(a,a+3);
  BackTrackPerm(0,3,perm);
*/
/*
  int a[]={8,6,2,3};
  int W=12;
  int R=19;
  vector<int> w(a,a+4);
  vector<int> x(4,0);
  BackTrackLoading(0,4,0,W,w,R,x);
*/
/*
  vector<int> x(8,0);
  BackTrackNqueen(0,8,x);
  */
 vector<vector<int> > res;
 vector<int> x;
 vector<int> flag(3,0);
 BackTrackSubset(0,3,res,x,flag);
 for(int i=0;i<res.size();i++)
 {
   copy(res[i].begin(),res[i].end(),ostream_iterator<int>(cout," "));
   cout<<endl;
 }
  return 0;
}
