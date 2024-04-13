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

   if(n==1||n==2)
   {
       s=1;
   }
   if(n>2)
    {
        s=a(n-1)+a(n-2);
    }
    else
    {
        return s;
    }
}
