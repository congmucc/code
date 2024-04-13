#include <iostream>

using namespace std;

int an(int m,int n)
{
   int c;
   c=m;
   m=n;
   n=c;
   cout <<m<<"\t"<<n;
}

int main()
{
    int m,n;
    cin>>m>>n;
    an(m,n);
    return 0;
}
