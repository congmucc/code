#include<iostream> 

using namespace std;

class Student {
	public :
		//类内声明，类外初始化（定义） 
		 static int mAge;
	private :
		static int mB;
};
//类外初始化  必须的 
int Student::mAge = 100;
int Student::mB;//但是类外访问不到私有的静态成员变量 

void test01() {
	
	//静态成员变量 不属于某个对象上  所有对象都共享一份数据
	//两种访问方式 
	
	//1通过对象进行访问
	Student stu1;
	cout<< stu1.mAge << endl;
	
	//2通过类名进行访问
	cout << Student::mAge <<endl; 
}

class Person {
    public :
    static void func() {
    	cout << "static void func调用" << endl;
	}
	
	static int m_A; 
	//  int m_B;    //不能访问非静态成员变量 
}; 

int Person::m_A = 10;

void test02() {
	/*
	1.所有对象共享同一个函数
	2.静态成员函数只能访问静态成员变量   即不能访问非静态成员变量 
	*/
	//1，通过对象进行访问
	Person p;
	p.func();
	
	//2，通过类名进行访问
	Person::func(); 
	
	
}

int main() {
	
	//静态成员变量 
	test01();
	
	//静态成员函数
	test02(); 
	return 0;
}
