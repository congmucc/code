#include<iostream>
using namespace std;
void fance(int a,int b)
{
	cout<<"*************"<<endl;
}
int *max(int a,int b)
{
	cout<<a<<b<<endl;
	return &a;
}
int main()
{
	int b,a;
	cin>>a>>b;
	void(*p)(int,int);
	p=fance;
	int *s=max(a,b);
	cout<<*s;
	return 0;
}
