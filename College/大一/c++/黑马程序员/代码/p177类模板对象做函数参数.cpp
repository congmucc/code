#include<iostream>
using namespace std;
#include<string>
template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age)
	{
		m_name=name;
		m_age=age;
	}
	
	T1 m_name;
	T2 m_age;
};
//1.ָ����������  (���)
void show1(Person<string,int>&p1)
{
	cout<<"���֣�"<<p1.m_name<<endl;
	cout<<"���䣺"<<p1.m_age<<endl;
}

//2.����ģ�廯 
template<class T1,class T2>
void show2(Person<T1,T2>&p2)
{
	cout<<"���֣�"<<p2.m_name<<endl;
	cout<<"���䣺"<<p2.m_age<<endl;
//�鿴ʲô���� 
//	cout<<"T1������Ϊ��"<<typeid(T1).name()<<endl;
//	cout<<"T2������Ϊ��"<<typeid(T2).name()<<endl;
}
//3.������ģ�廯 
template<class T>
void show3(T &p3)
{
	cout<<"���֣�"<<p3.m_name<<endl;
	cout<<"���䣺"<<p3.m_age<<endl;
}

void test01()
{
	Person<string,int>p1("�����",999);
	show1(p1);
	Person<string,int>p2("��˽�",777);
	show2(p2);
	Person<string,int>p3("��ɮ",30);
	show3(p3); 
}

int main()
{
	test01();
	return 0;
}
