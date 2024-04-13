#include<iostream>

using namespace std;
class Date
{
	public:
		Date(int y=1949,int m=10,int d=1)
		{
			year=y;
			mouth=m;
			day=d;
		}
		void show_Date()
		{
			cout<<year<<"\t"<<mouth<<"\t"<<day<<endl;
		}
	private:
        int year;
        int mouth;
        int day;
		};
class Doctor
{
	public:
		Doctor(int i=1001,string n="wang",char s='f',int year=1949,int mouth=10,int day=1)
		{
			id=i;
			name=n;
			sex=s;
			Date d(year,mouth,day);
			age=d;
		};
		Do(int i=1001,string n="wang",char s='f',int year=1949,int mouth=10,int day=1)
		{
			id=i;
			name=n;
			sex=s;
			Date d(year,mouth,day);
			age=d;
		};
		void show(); 
	private:
        int id;
        string name;
        char sex;
        Date age;
       
};

void Doctor::show()
{
	cout<<id<<"\t"<<name<<"\t"<<sex<<endl;
	age.show_Date();
}
int main()
{
	Doctor dic[10]={Doctor(1001,"zhang",'f',1949,10,2),
             Doctor(1002,"wang",'f',1950,1,1)};
    int id,year,month,day;
    string name;
    char sex;
    for(int i=0;i<10;i++)
    {
    	cin>>id>>name>>sex>>year>>month>>day;
    	dic[i].Do(id,name,sex,year,month,day);
	}
	for(int i=0;i<10;i++)
	    dic[i].show();
	return 0;
}
