#include<bits/stdc++.h>
using namespace std;

class peo
{
	private:
		int num;
		int quantity;
		double price;
		static double discount;
		static double sum;
		static int n;
	public:
		peo(int a,int b,double c):num(a),quantity(b),price(c){};
		void t();
		static double average();
		static void display();	
};
void peo::t()
{
	double v=1;
	if(quantity>10)
	{
		v=0.98;
	}
	sum+=quantity*price*v*(1-discount);
	n=n+quantity;
}
double peo::average()
{
	return (sum/n);
}
void peo::display()
{
	cout<<sum<<endl;
	cout<<average()<<endl;
}
double peo::discount=0.6;
double peo::sum=0;
int peo::n=0;

int main()
{
	peo people[3]={peo(101,5,23.5),peo(102,12,23.56),peo(103,100,21.5)};
	for(int i=0;i<3;i++)
	{
		people[i].t();
	}
	peo::display();
	return 0;
}


