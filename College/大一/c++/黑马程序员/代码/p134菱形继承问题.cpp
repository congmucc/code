#include<iostream> 
using namespace std;

//基类 
class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//先看黑马程序员的这一节    来看虚函数表 和虚函数指针来访问指针 
//只有看https://www.cnblogs.com/qg-whz/p/4909359.html  对象的内存布局

//此时公共的父类Animal称为虚基类

//羊 
class Sheep : virtual public Animal {};

//驼 
class Tuo   : virtual public Animal {};

//羊驼 
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {

	test01();

	system("pause");

	return 0;
}
