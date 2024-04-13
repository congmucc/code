#include<iostream>
using namespace std;
#include<string>

template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		m_name=name;
		m_age=age;
	}
	
	void show()
	{
		cout<<"������"<<m_name<<endl;
		cout<<"���䣺"<<m_age<<endl; 
	}
	
private:
	NameType m_name;
	AgeType m_age;
};


void test01()
{
	Person<string,int>p1("�����",1900);
	p1.show();
}

int main()
{
	test01();
	return 0;
}
