#include <iostream>

using namespace std;
int an(int n)
{
   int x=0,t=n;
   while(n)
   {
       x=x*10+n%10;
       n=n/10;
   }
   if(t==x)
   {
       return 1;
   }
}
int main()
{
    for(int i=1;i<=999999;i++)
	{
		if(an(i)==1)
		{
			if(i%10!=0)
			{
				cout<<i<<endl;
			}
		}
	}

    return 0;
}
