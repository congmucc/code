#include<iostream>
using namespace std;
class Person
{
	public:
	Person(int a,int height)
	{
		an=a;
		Height=new int(height);
		cout<<"�в�������"<<endl;
	}

	Person(const Person &p)//�������� 
	{
		cout<<"�������캯����"<<endl;
		an=p.an;
		Height=new int(*p.Height);//��� ��Ҫ��*ȡ���� 
	}
	~Person()
	{
		//�Ѷ������ͷ� 
		if(Height!=NULL)
		{
			delete Height;
			Height=NULL;//��ֹ��ָ�� 
		}
		
		cout<<"��������"<<endl; 
	}
	int an;
	int *Height;
};
void test01()
{
    Person p1(18,29);
    cout<<"p1��an��"<<p1.an<<"p1���Ϊ��"<<*p1.Height<<endl;//��һ��*ȡ���� 
    Person p2(p1);
    cout<<"p2��an��"<<p2.an<<"p2���Ϊ��"<<*p2.Height<<endl;
}
int main()
{
    test01();
    
    system("pause");
	return 0;
 } 
