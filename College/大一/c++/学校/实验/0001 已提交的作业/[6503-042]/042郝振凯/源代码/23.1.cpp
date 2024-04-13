#include<bits/stdc++.h>
using namespace std;

class matrix
{
	private:
		int m[2][3];
	public:
		matrix();
		void input();
		void show();
		friend matrix operator+(matrix &,matrix &);	
};
matrix::matrix()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			m[i][j]=0;
		}
	}
}
matrix operator+(matrix &a,matrix &b)
{
	matrix c;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			c.m[i][j]=a.m[i][j]+b.m[i][j];
		}
	}
	return c;
}
void matrix::input()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>m[i][j];
		}
	}
}
void matrix::show()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j<2)
			{
				cout<<m[i][j]<<" ";
			}
			else
			{
				cout<<m[i][j]<<endl;
			}
		}
	}
}
int main()
{
	matrix a,b,c;
	a.input();
	b.input();
	c=a+b;
	c.show();
	return 0;
}

















