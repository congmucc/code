#include<bits/stdc++.h>
using namespace std;

class Complex
{
	private:
		double real;
		double imag;
	public:
		Complex(){real=0;imag=0;};
		friend Complex operator+(Complex &,Complex &);
		friend Complex operator-(Complex &,Complex &);
		friend Complex operator*(Complex &,Complex &);
		friend Complex operator/(Complex &,Complex &);
		void input();
		void output();
};
Complex operator+(Complex &a,Complex &b)
{
	Complex c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}
Complex operator-(Complex &a,Complex &b)
{
	Complex c;
	c.real=a.real-b.real;
	c.imag=a.imag-b.imag;
	return c;
}
Complex operator*(Complex &a,Complex &b)
{
	Complex c;
	c.real=a.real*b.real-a.imag*b.imag;
	c.imag=a.real*b.imag+a.imag*b.real;
	return c;
}
Complex operator/(Complex &a,Complex &b)
{
	Complex c;
	c.real=(a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
	c.imag=(a.imag*b.real-a.real*b.imag)/(b.real*b.real+b.imag*b.imag);
	return c;
}
void Complex::input()
{
	cin>>real>>imag;
}
void Complex::output()
{
	cout<<"("<<real<<"+"<<imag<<"i)"<<endl;
}

int main()
{
	Complex a,b,c,d,e,f;
	a.input();
	b.input();
	c=a+b;
	d=a-b;
	e=a*b;
	f=a/b;
	c.output();
	d.output();
	e.output();
	f.output();
	return 0;
}



















