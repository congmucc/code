#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int i,m,j;
    int a[10];
    for(i=0;i<10;i++)
   cin>>a[i];
   m=a[0];

   for(i=0;i<10;i++)
    {
        if(a[i]<m)
   {
       m=a[i];
       j=i;
   }
   }
    cout <<"min="<<m<<'\t'<<"об╠Й="<<j;
 return 0;
}
