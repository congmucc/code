#include<iostream>
using namespace std;
class Person1
{
public:
	void show1()
	{
		cout<<"Person1 show"<<endl;
	}
	
};

class Person2
{
public:
	void show2()
	{
		cout<<"Person2 show"<<endl;
	}
	
	
};

template<class T>
class MyClass
{
public:
    T obj;
    void func1()
    {
    	obj.show1();
	}
	void func2()
    {
    	obj.show2();
	}
};

void test01()
{
	MyClass<Person1>p1;
	MyClass<Person2>p2;
	p1.func1();
	p2.func2();
}

int main()
{
	
	test01();
	return 0;
}
