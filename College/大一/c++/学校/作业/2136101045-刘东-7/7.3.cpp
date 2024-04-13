#include <iostream>
#include <math.h>
using namespace std;
   double exp(int x,int n)
  {
  int s;
  s=x^n;
  return s;
  }
int main()
{
    int a,b;
    cin>>a>>b;
    int z=exp(a,b);
  cout<<z;
    return 0;
 }
