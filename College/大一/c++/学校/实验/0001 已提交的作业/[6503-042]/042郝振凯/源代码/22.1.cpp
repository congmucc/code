#include<bits/stdc++.h>
using namespace std;

int water(int n)
{
	int sum=0;
	int a,b,c;
	a=n/100;
	b=(n%100)/10;
	c=n%10;
	sum=a*a*a+b*b*b+c*c*c;
	return sum;
}


int main()
{
	for(int i=100;i<1000;i++)
	{
		if(water(i)==i)
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
