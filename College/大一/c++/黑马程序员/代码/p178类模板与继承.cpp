#include<iostream>
using namespace std;


template<class T>
class Base
{
public:
	T m;
};

//����ʹ��ģ�� 
//class Son:public Base  ����Ҫָ������ʲô���͡� 
class Son:public Base<int>
{
};


//�������ģ�� 
template<class T1,class T2>
class Son2:public Base<T2>
{
	T1 obj;
};

void test01()
{
	Son2<int ,char>s1;//intָ�����T1��charָ�����T2. 
}
int main()
{
	test01();
	return 0;
 } 
