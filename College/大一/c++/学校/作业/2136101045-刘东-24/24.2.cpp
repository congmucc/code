#include<iostream>
using namespace std;

class RMB
{
	private:
		int yuan;
		int jiao;
		int fen;
	public:
		RMB(){yuan=0;jiao=0;fen=0;}
		RMB(int y,int j,int f);
		friend RMB operator+(RMB &,RMB &);
		friend RMB operator-(RMB &,RMB &);
		RMB operator++();
		RMB operator++(int);
		RMB operator--();
		RMB operator--(int);
		friend ostream& operator<<(ostream&,RMB &);
		friend istream& operator>>(istream&,RMB &);
};
RMB operator+(RMB &x,RMB &y)
{
	RMB z;
	z.yuan=x.yuan+y.yuan;
	z.jiao=x.jiao+y.jiao;
	z.fen=x.fen+y.fen;
	return z;
}
RMB operator-(RMB &x,RMB &y)
{
	RMB z;
	z.yuan=x.yuan-y.yuan;
	z.jiao=x.jiao-y.jiao;
	z.fen=x.fen-y.fen;
	return z;
}
RMB RMB::operator++()//Ç°ÖÃ
{
	if(++fen>=10)
	{
		fen-=10;
		if(++jiao>=60)
		{
			jiao-=10;
			++yuan;
		}
	}
	return *this;
}
RMB RMB::operator++(int)
{
	RMB temp(*this);
	fen++;
	if(fen>=10)
	{
		fen-=10;
		jiao++;
		if(jiao>=10)
		{
			jiao-=10;
			yuan++;
		}
	}
	return temp;
}
RMB RMB::operator--()//Ç°ÖÃ
{
	if(--fen>=10)
	{
		fen-=10;
		if(--jiao>=60)
		{
			jiao-=10;
			--yuan;
		}
	}
	return *this;
}
RMB RMB::operator--(int)
{
	RMB temp(*this);
	fen--;
	if(fen>=10)
	{
		fen-=10;
		jiao--;
		if(jiao>=10)
		{
			jiao-=10;
			yuan--;
		}
	}
	return temp;
}
istream& operator>>(istream&input,RMB &x)
{
	input>>x.yuan>>x.jiao>>x.fen;
}
ostream& operator<<(ostream&output,RMB &x)
{
	output<<x.yuan<<"yuan"<<x.jiao<<"jiao"<<x.fen<<"fen"<<endl;
}

int main()
{
	RMB r1,r2,r3;
	cin>>r1>>r2;
	r3=r1+r2;
	r3=r1-r2;
	++r1;
	r3=r1++;
	cout<<"r1="<<r1<<endl;
	cout<<"r2="<<r2<<endl;
	cout<<"r3="<<r3<<endl;
	cout<<"r1="<<r1<<endl;
}































