#include<iostream>
using namespace std;
class AbstractCalculator
{
public:
    virtual int getResult()
	{
		return 0;
	}	
	int m_num1;
	int m_num2;
};
class AddCalculator : public AbstractCalculator
{
	public:
	int getResult()
	{
		return m_num1+m_num2;
	}
};
class DeCalculator : public AbstractCalculator
{
	int getResult()
	{
		return m_num1-m_num2;
	}
};
class muCalculator : public AbstractCalculator
{
	int getResult()
	{
		return m_num1*m_num2;
	}
};
void test01()
{
	//多态的使用条件 ： 
	// 父类指针或者引用到子类对象 (直接在网上查一下，就懂了https://blog.csdn.net/qq_21989927/article/details/111226696)
	//指针方式 
	AbstractCalculator *p=new AddCalculator;
	p->m_num1=10;
	p->m_num2=10;
	cout<<"指针方法1："<<p->getResult()<<endl;
	//指针方法2
	AddCalculator p1; 
	AbstractCalculator *p2=&p1;
	cout<<"指针方法2："<<p2->getResult()<<endl;
	
	cout<<"--------------分割线----------------"<<endl;
	//引用方式 
    //需要再设定一个新的实现函数才行，看上面的链接。 
	
	cout<<"--------------分割线----------------"<<endl;
	//正常的 
	AddCalculator p3;
	p3.m_num1=10;
	p3.m_num2=15;
	cout<<"正常方法："<<p3.getResult()<<endl;
}
int main()
{
	test01();
	return 0;
}
