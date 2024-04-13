#include<iostream>
using namespace std;
#include<string>
class Animal
{
public:	
	Animal()
	{
		cout<<"Animal的构造函数"<<endl;
	}
	//虚析构
	//利用虚析构可以解决父类指针释放子类对象不干净的问题 
//	virtual ~Animal()
//	{
//		cout<<"Animal的析构函数"<<endl;
//	}
    //纯虚析构函数的声明    要声明一下 
    //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象 
	virtual ~Animal()=0; 
    
	virtual void speak() =0;
};
//纯虚析构函数 
Animal::~Animal()
{
	cout<<"Animal的纯析构函数"<<endl;
}

class Cat : public Animal
{
public:
	Cat(string name)
	{
		m_Name=new string(name);
		cout<<"Cat的构造函数"<<endl; 
	}
	~Cat()
	{

		if(m_Name!=NULL)
		{
			cout<<"Cat的析构函数"<<endl;
			delete m_Name;
			m_Name=NULL;
		}
	}
	void speak()
	{
		
		cout<<*m_Name<<"在说话"<<endl; 
	}
	string *m_Name;
};
void test01()
{
	Animal *p=new Cat("tom");
	p->speak();
	delete p;
}
int main()
{
	test01();
	return 0;
 } 
