#include<bits/stdc++.h>
using namespace std;

class cycle
{
	private:
		double r;
		const static double pi=3.14;
	public:
		cycle(){r=10;};
		void cinr();
		double ccycle();
		double scycle();
};
void cycle::cinr()
{
	int n;
	cin>>n;
	r=n;
}
double cycle::ccycle()
{
	double pe=0;
	pe=2*pi*r;
	return pe;
}
double cycle::scycle()
{
	double S=0;
	S=pi*r*r;
	return S;
}


int main()
{
	cycle c1;
	c1.cinr();
	cout<<c1.ccycle()<<endl;
	cout<<c1.scycle()<<endl;
}

