#include<iostream>
using namespace std;

#include"Person.hpp"


//#include<string>

//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//
//	void showPerson();
//
//	T1 m_name;
//	T2 m_age;
//};


//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	m_name = name;
//	m_age = age;
//}
//
//
//template<class T1,class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "Ãû×Ö£º" << m_name << "ÄêÁä£º" << m_age << endl;
//}

void test01()
{
	Person<string, int>p1("Îò¿Õ", 9999);
	p1.showPerson();
}

int main()
{
	test01();
	return 0;
}