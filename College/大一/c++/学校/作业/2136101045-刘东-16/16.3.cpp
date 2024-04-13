#include <iostream>

using namespace std;
int a(int m,int n);
int main()
{
    int m,n;
    cin>>m>>n;
    a(m,n);
    return 0;
}
int a(int m,int n)
{
    if(m==1)
    {
        m=2;
    }
int j;
 for(int i=m;i<=n;i++)
  {
      for(j=2;j<i;j++)
      {
          if(i%j==0)
          {
             break;
          }
      }
        if(j==i)
		cout<<i<<endl;

  }
}
