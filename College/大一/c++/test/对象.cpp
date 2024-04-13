#include<iostream>
using namespace std;
#include <string>
class Phone
{
	public:
		Phone(string name)
		{
			m_PName=name;
		}
		string m_PName;
}; 
class Person
{
	public:
		//必须要初始化列表才行； 
		Person(string name,string phone):m_Name(name),m_Phone(phone)
		{
             cout<<"初始化列表"<<endl; 
        }


		
		
		string m_Name;
		Phone m_Phone;
};
void test01()
{
	Person p("张三","xiaomi");
	Person p2(p);
	cout<<"名字"<<p.m_Name<<"手机"<<p.m_Phone.m_PName<<endl;
	cout<<"名字"<<p2.m_Name<<"手机"<<p2.m_Phone.m_PName<<endl;
}
int main()
{
	test01();
	return 0;
}
