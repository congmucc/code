#include<iostream>
using namespace std;
class Animal
{
	public:
		virtual void speak()
		{
			cout<<"������˵��"<<endl;
		}
};
class Cat:public Animal
{
	public:
		void speak()
		{
			cout<<"Сè��˵��"<<endl; 
		}
};
 
void DoSpeak(Animal &animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	DoSpeak(cat);
}
int main()
{
	test01();
	return 0;
}
