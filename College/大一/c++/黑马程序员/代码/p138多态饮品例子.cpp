#include<iostream>
using namespace std;
class AbstractDrinking
{
public:
    virtual void Boil() = 0;
	virtual void Brew()	= 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
    void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
	
};
class Coffee : public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout<<"热水"<<endl;
	}
	virtual void Brew()
	{
		cout<<"冲泡咖啡"<<endl; 
	}
	virtual void PourInCup()
	{
		cout<<"倒入杯中"<<endl; 
	}
	void PutSomething()
	{
		cout<<"加入辅料"<<endl; 
	}	

}; 

void test01()
{
	AbstractDrinking *p=new Coffee;
	p->MakeDrink();
	delete p;
	p=NULL;
 } 
void DoDrink(AbstractDrinking *p1)
{
	p1->MakeDrink();
}
void test02()
{

	DoDrink(new	Coffee);
}
int main()
{
	test01();
	cout<<endl;
	test02();
	return 0;
} 
