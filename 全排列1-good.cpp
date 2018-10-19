#include<iostream>
#include <algorithm>
using namespace std;
void perm(int i,int n,int a[])
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            swap(a[j], a[i]);
            perm(i+1,n,a);
            swap(a[j],a[i]);
        }
    }
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
        a[i]=i+1;
    perm(0, n, a);
    return 0;
    
}
//
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
char b[]={'a','b','c','d'};
vector<char> a(b,b+4);
void perm(int i,int n)
{
    if(i==n)copy(a.begin(),a.end(),ostream_iterator<char>(cout," ")),cout<<endl;
    if(i<n)
    {
        for(int j=i;j<n;j++)
        {
            swap(a[i],a[j]);
            perm(i+1,n);
            swap(a[i],a[j]);
        }
    }
}
int main()
{
    perm(0,4);
    return 0;
}
//STL---《algorithm》中的两个函数next_permutation和prev_permutation。链接分别是next_permutation，prev_permutation。

next_permutation:对于当前的排列，如果在字典序中还存在下一个排列，返回真，并且将下一个排列赋予当前排列，如果不存在，就把当前排列进行递增排序。

prev_permutation对于当前的排列，如果在字典序中还存在前一个排列，返回真，并且将前一个排列赋予当前排列，如果不存在，就把当前排列进行递减排序。

那么利用next_permutation可以很轻松的实现全排列。

代码如下：

    #include<iostream>  
    #include<algorithm>  
      
    using namespace std;  
      
    int arry[3] = { 1,2,3 };//len==3;  
      
    void Permutation()  
    {  
        do  
            printf("%d%d%d\n", arry[0], arry[1], arry[2]);  
        while (next_permutation(arry, arry + 3));  
          
    }  
      
    int main()  
    {  
      
        Permutation();  
      
        return 0;  
    }  
//
    举个例子，现在我们要找21543的下一个排列，我们可以从左至右逐个扫描每个数，看哪个能增大（至于如何判定能增大，是根据如果一个数右面有比它大的数存在，那么这个数就能增大），我们可以看到最后一个能增大的数是：x = 1。而1应该增大到多少？1能增大到它右面比它大的那一系列数中最小的那个数，即：y = 3，故此时21543的下一个排列应该变为23xxx，显然 xxx(对应之前的B’）应由小到大排，于是我们最终找到比“21543”大，但字典顺序尽量小的23145，找到的23145刚好比21543大。

抽象概括一下上面的例子就是“二找、一交换、一翻转”。

    一找：找到排列中最后（最右）一个升序的首位位置i，x = ai
    二找：找到排列中第i位右边最后一个比ai 大的位置j，y = aj
    一交换：交换x，y
    一翻转：把第(i+ 1)位到最后的部分翻转
*升序：相邻两个位置ai < ai+1，ai 称作该升序的首位

 找21543的下一个排列，套用“二找、一交换、一翻转”就是

一找: 找到排列中最后（最右）一个升序的首位, x = 1
二找: 找到排列中1的右边最后一个比1大的位置，y = 3
一交换：1和3交换，得23541
一翻转：翻转541，得23145
--------------------- 
作者：eva_qu 
来源：CSDN 
原文：https://blog.csdn.net/beggar200/article/details/50245207?utm_source=copy 
版权声明：本文为博主原创文章，转载请附上博文链接！
bool FindNextPermutation(char* perm, int num)
{
    int i = 0;
    for(i = num - 2; (perm[i] >= perm[i+1]) && i >= 0; --i)
        ; // Find x
    if(i < 0)
    {
        return false;  // The input string is a single character
    }
    int j = 0;
    for(j = num - 1; (j > i) && perm[j] <= perm[i]; --j)
        ; // Find y
 
    swap(perm[i], perm[j]);  // swap x and y
    reverse(perm + i + 1, perm + num); // reverse B'
    return true;
}
--------------------- 
作者：eva_qu 
来源：CSDN 
原文：https://blog.csdn.net/beggar200/article/details/50245207?utm_source=copy 
版权声明：本文为博主原创文章，转载请附上博文链接！
