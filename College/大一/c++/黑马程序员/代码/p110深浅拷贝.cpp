#include<iostream>
using namespace std;
class Person
{
	public:
		Person(int age,int height)
		{
			m_age=age;
			m_height = new int(height);
		    cout<<"Person�вι��캯��"<<endl; 
		}
		Person(const Person &p)
		{
			m_age=p.m_age;
			m_height=new int (*p.m_height);
		}
		~Person()
		{
			cout<<"Person����������"<<endl; 
			if(m_height != NULL)
			{
				delete m_height;
				m_height = NULL;
			}
		}
		int m_age;
		int *m_height; 
		
};
void test01()
{
	Person p1(18,185);
	cout<<"p1������: "<<p1.m_age<<"  p1�����: "<<*p1.m_height<<endl;
	Person p2(p1);
	cout<<"p2������: "<<p2.m_age<<"  p2�����: "<<*p2.m_height<<endl;
	
	
}
int main()
{
	test01();
	return 0;
} 
