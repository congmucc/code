#include <iostream>
using namespace std;
const int m=110;
int main()
{
   int n,i,j;
   int a[m][m];
   cin>>n;
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
   int sum=0;
   for(i=0;i<n;i++)
    sum+=(a[i][i]+a[i][n-1-i]);
   cout<<"sum="<<sum;
    return 0;
}
