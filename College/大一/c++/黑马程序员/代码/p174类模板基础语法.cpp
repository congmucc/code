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
		cout<<"ĞÕÃû£º"<<m_name<<endl;
		cout<<"ÄêÁä£º"<<m_age<<endl; 
	}
	
private:
	NameType m_name;
	AgeType m_age;
};


void test01()
{
	Person<string,int>p1("ËïÎò¿Õ",1900);
	p1.show();
}

int main()
{
	test01();
	return 0;
}
