#include <iostream>

using namespace std;
int a(int a);
int main()
{
    int n;
    cin>>n;
    a(n);
    cout<<a(n);
    return 0;
}
int a(int n)
{
   int s=1;

   s*=n;
   if(n>1)
    {
        s*=a(n-1);
    }
    else
    {
        return s;
    }
}
