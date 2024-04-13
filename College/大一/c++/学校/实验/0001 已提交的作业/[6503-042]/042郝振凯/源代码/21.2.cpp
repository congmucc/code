#include<bits/stdc++.h>
using namespace std;
class student
{
	private:
		double score[3];
	public:
		void cinscore();
		double countAvg();
		void displayAvg();
};
void student::cinscore()
{
	for(int i=0;i<3;i++)
	{
		cin>>score[i];
	}
}
double student::countAvg()
{
	double a;
	for(int i=0;i<3;i++)
	{
		a+=score[i];
	}
	return (a/3);
}
void student::displayAvg()
{
	cout<<countAvg()<<endl;
}


int main()
{
	student s[3];
	for(int i=0;i<3;i++)
	{
		s[i].cinscore();
		s[i].countAvg();
		s[i].displayAvg();
	}
	return 0;
}


