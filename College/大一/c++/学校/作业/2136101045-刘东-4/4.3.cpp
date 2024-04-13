#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,sum;
	cin>>x;
	if(x<=100000)
	{
		sum=x*0.1;
	}
	else if(x<=200000)
	{
		sum=10000.000+(x-100000)*0.075;
	}
	else if(x<=400000)
	{
		sum=17500+(x-200000)*0.05;
	}
	else if(x<=600000)
	{
		sum=27500+(x-400000)*0.03;
	}
	else if(x<=1000000)
	{
		sum=47500+(x-600000)*0.015;
	}
	else 
	{
		sum=53500+(x-1000000)*0.01;
	}
	cout<<sum<<endl;
	return 0;	
}
