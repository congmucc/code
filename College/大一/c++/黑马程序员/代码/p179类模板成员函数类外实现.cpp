#include<iostream>
using namespace std;
#include<string>

template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age);
	void show(); 
	T1 m_name;
	T2 m_age;
};
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
	m_name=name;
	m_age=age;
}
template<class T1,class T2>
void Person<T1,T2>::show()
{
	cout<<"ĞÕÃû£º"<<m_name<<"  ÄêÁä£º"<<m_age<<endl;
}
	
void test01()
{
	Person<string,int>p1("ËïÎò¿Õ",999);
	p1.show();
}

int main()
{
	test01();
	return 0;
}
