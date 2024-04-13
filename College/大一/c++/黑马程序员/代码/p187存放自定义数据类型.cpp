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
	Person p1("�����",999);
	Person p2("��˽�",999);
	Person p3("��ɮ",999);
	Person p4("ɳɮ",999);
	Person p5("������",999);
	
	
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
	Person p1("�����",999);
	Person p2("��˽�",999);
	Person p3("��ɮ",999);
	Person p4("ɳɮ",999);
	Person p5("������",999);
	
	
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	
		for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
	{
		
		//�������ɵ�ַ�ĵ�ַ   *itԭ����һ����������Ϊ<Person*>  ����˵vector�������ǵ�ַ����Ҫ���ν��ַ�� 
//		cout<<"Name: "<<(*(*it)).m_Name<<" Age: "<<(*(*it)).m_Age<<endl;


        //(*it).m_Name == it->m_Name     
		cout<<"Name: "<<(*it)->m_Name<<" Age: "<<(*it)->m_Age<<endl;
		
		//�õڶ����ɣ��ڶ������ã�����������ַ->����    ������ 
	}
	
	
}

int main()
{
//	test01();
	
	test02(); 
	return 0;
}
