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
//1.指定传入类型  (最常用)
void show1(Person<string,int>&p1)
{
	cout<<"名字："<<p1.m_name<<endl;
	cout<<"年龄："<<p1.m_age<<endl;
}

//2.参数模板化 
template<class T1,class T2>
void show2(Person<T1,T2>&p2)
{
	cout<<"名字："<<p2.m_name<<endl;
	cout<<"年龄："<<p2.m_age<<endl;
//查看什么类型 
//	cout<<"T1的类型为："<<typeid(T1).name()<<endl;
//	cout<<"T2的类型为："<<typeid(T2).name()<<endl;
}
//3.整个类模板化 
template<class T>
void show3(T &p3)
{
	cout<<"名字："<<p3.m_name<<endl;
	cout<<"年龄："<<p3.m_age<<endl;
}

void test01()
{
	Person<string,int>p1("孙悟空",999);
	show1(p1);
	Person<string,int>p2("猪八戒",777);
	show2(p2);
	Person<string,int>p3("唐僧",30);
	show3(p3); 
}

int main()
{
	test01();
	return 0;
}
