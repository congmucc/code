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
		//����Ҫ��ʼ���б���У� 
		Person(string name,string phone):m_Name(name),m_Phone(phone)
		{
             cout<<"��ʼ���б�"<<endl; 
        }


		
		
		string m_Name;
		Phone m_Phone;
};
void test01()
{
	Person p("����","xiaomi");
	Person p2(p);
	cout<<"����"<<p.m_Name<<"�ֻ�"<<p.m_Phone.m_PName<<endl;
	cout<<"����"<<p2.m_Name<<"�ֻ�"<<p2.m_Phone.m_PName<<endl;
}
int main()
{
	test01();
	return 0;
}
