#include<iostream>
using namespace std;
#include<string>
class Animal
{
public:	
	Animal()
	{
		cout<<"Animal�Ĺ��캯��"<<endl;
	}
	//������
	//�������������Խ������ָ���ͷ�������󲻸ɾ������� 
//	virtual ~Animal()
//	{
//		cout<<"Animal����������"<<endl;
//	}
    //������������������    Ҫ����һ�� 
    //���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ�������� 
	virtual ~Animal()=0; 
    
	virtual void speak() =0;
};
//������������ 
Animal::~Animal()
{
	cout<<"Animal�Ĵ���������"<<endl;
}

class Cat : public Animal
{
public:
	Cat(string name)
	{
		m_Name=new string(name);
		cout<<"Cat�Ĺ��캯��"<<endl; 
	}
	~Cat()
	{

		if(m_Name!=NULL)
		{
			cout<<"Cat����������"<<endl;
			delete m_Name;
			m_Name=NULL;
		}
	}
	void speak()
	{
		
		cout<<*m_Name<<"��˵��"<<endl; 
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
