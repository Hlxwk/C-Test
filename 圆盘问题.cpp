#include <iostream>
using namespace std;
void move_func(int n,char x,char y)
{
    cout<<n<<" : "<<x<<" -> "<<y<<endl;
}
void hanoi_func(int n,char x,char y,char z)
{
    if(n==1)move_func(1, x, z);
    else
    {
        hanoi_func(n-1, x, z, y);
        move_func(n, x, z);
        hanoi_func(n-1, y, x, z);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        hanoi_func(n, 'A', 'B', 'C');
    }
    return 0;
}
