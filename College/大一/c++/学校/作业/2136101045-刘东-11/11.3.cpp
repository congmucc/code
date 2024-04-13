#include <iostream>

using namespace std;


int main()
{
 int i,j;
   int a[3][3];
   int b[3][3];
   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    cin>>a[i][j];
}
   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    cin>>b[i][j];
   }
      for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
        cout <<a[3][3]+b[3][3];
   }

    return 0;
}
