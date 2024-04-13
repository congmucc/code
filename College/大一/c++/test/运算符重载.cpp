#include<iostream>
using namespace std;
class Person
{
	public:

		int m_a;
		int m_b;
        Person operator+(Person &p2)
	    {
	    	Person temp;
	    	temp.m_a=this->m_a+p2.m_a;
            temp.m_b=this->m_b+p2.m_b;
			return temp;	    	
		}
};



void test01()
{
	Person p1,p2;
	p1.m_a=10;
	p1.m_b=10;
	p2.m_a=10;
	p2.m_b=10;
	Person p3;
	p3=p1+p2; 
	cout<<p3.m_a;
	
}

int main()
{
	test01();
	return 0;
}
