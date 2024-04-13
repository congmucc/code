#include<iostream>
using namespace std;

template<typename T> 
void myswap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

void test01()
{
	int a,b;
	a=10;
	b=23;
	myswap(a,b);
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
}

int main()
{
	test01();
	return 0;
}
