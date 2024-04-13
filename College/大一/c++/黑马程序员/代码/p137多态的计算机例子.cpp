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
	//��̬��ʹ������ �� 
	// ����ָ��������õ�������� (ֱ�������ϲ�һ�£��Ͷ���https://blog.csdn.net/qq_21989927/article/details/111226696)
	//ָ�뷽ʽ 
	AbstractCalculator *p=new AddCalculator;
	p->m_num1=10;
	p->m_num2=10;
	cout<<"ָ�뷽��1��"<<p->getResult()<<endl;
	//ָ�뷽��2
	AddCalculator p1; 
	AbstractCalculator *p2=&p1;
	cout<<"ָ�뷽��2��"<<p2->getResult()<<endl;
	
	cout<<"--------------�ָ���----------------"<<endl;
	//���÷�ʽ 
    //��Ҫ���趨һ���µ�ʵ�ֺ������У�����������ӡ� 
	
	cout<<"--------------�ָ���----------------"<<endl;
	//������ 
	AddCalculator p3;
	p3.m_num1=10;
	p3.m_num2=15;
	cout<<"����������"<<p3.getResult()<<endl;
}
int main()
{
	test01();
	return 0;
}
