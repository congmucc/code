#include<iostream>
using namespace std;


template<class T>
class Base
{
public:
	T m;
};

//子类使用模板 
//class Son:public Base  错误，要指定父类什么类型。 
class Son:public Base<int>
{
};


//子类灵活模板 
template<class T1,class T2>
class Son2:public Base<T2>
{
	T1 obj;
};

void test01()
{
	Son2<int ,char>s1;//int指子类的T1，char指父类的T2. 
}
int main()
{
	test01();
	return 0;
 } 
