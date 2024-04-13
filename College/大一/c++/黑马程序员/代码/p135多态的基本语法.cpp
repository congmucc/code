#include<iostream>
using namespace std;
class Animal
{
	public:
		virtual void speak()
		{
			cout<<"动物在说话"<<endl;
		}
};
class Cat:public Animal
{
	public:
		void speak()
		{
			cout<<"小猫在说话"<<endl; 
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
