#include <iostream>

using namespace std;
int a()
{
    int i,a,b,c;
    for(i=100;i<1000;i++)

    {
       a=i/100;
       b=(i/10)%10;
       c=i%10;
       if(i==a*a*a+b*b*b+c*c*c)
       {
    cout<<i<<"\t";
       }
    }
}
int main() {

   a();
   return 0;
}
