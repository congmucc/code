#include<bits/stdc++.h>
using namespace std;

int num(int n)
{
	int x=0,temp=n;
	while(n)
	{
		x=x*10+n%10;
		n=n/10;
	}
	if(x==temp)
	{
		return 1;
	}
}

int main()
{
	for(int i=1;i<=999999;i++)
	{
		if(num(i)==1)
		{
			if(i%10!=0)
			{
				cout<<i<<endl;
			}
		}
	}
	return 0;
} 
