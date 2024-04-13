#include<iostream>
using namespace std;
#include<string>
#include<vector>


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name=name;
		this->m_Age=age;
	}
	
	string m_Name;
	int m_Age;
};

void test01()
{
	vector<Person> v;
	Person p1("孙悟空",999);
	Person p2("猪八戒",999);
	Person p3("唐僧",999);
	Person p4("沙僧",999);
	Person p5("白龙马",999);
	
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
//		cout<<"Name: "<<(*it).m_Name<<" Age: "<<(*it).m_Age<<endl;
		cout<<"Name: "<<it->m_Name<<" Age: "<<it->m_Age<<endl;
	}
	
	 
}

void test02()
{
	vector<Person*> v;
	Person p1("孙悟空",999);
	Person p2("猪八戒",999);
	Person p3("唐僧",999);
	Person p4("沙僧",999);
	Person p5("白龙马",999);
	
	
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	
		for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
	{
		
		//可以理解成地址的地址   *it原本是一个常量，因为<Person*>  所以说vector里面存的是地址，故要两次解地址。 
//		cout<<"Name: "<<(*(*it)).m_Name<<" Age: "<<(*(*it)).m_Age<<endl;


        //(*it).m_Name == it->m_Name     
		cout<<"Name: "<<(*it)->m_Name<<" Age: "<<(*it)->m_Age<<endl;
		
		//用第二个吧，第二个好用，，，，，地址->对象    ！！！ 
	}
	
	
}

int main()
{
//	test01();
	
	test02(); 
	return 0;
}
