#include<iostream>
using namespace std;
class Person
{
	public:
	Person(int a,int height)
	{
		an=a;
		Height=new int(height);
		cout<<"有参数构造"<<endl;
	}

	Person(const Person &p)//析构函数 
	{
		cout<<"拷贝构造函数："<<endl;
		an=p.an;
		Height=new int(*p.Height);//深拷贝 ，要加*取内容 
	}
	~Person()
	{
		//把堆区的释放 
		if(Height!=NULL)
		{
			delete Height;
			Height=NULL;//防止空指针 
		}
		
		cout<<"析构函数"<<endl; 
	}
	int an;
	int *Height;
};
void test01()
{
    Person p1(18,29);
    cout<<"p1的an："<<p1.an<<"p1身高为："<<*p1.Height<<endl;//加一个*取内容 
    Person p2(p1);
    cout<<"p2的an；"<<p2.an<<"p2身高为："<<*p2.Height<<endl;
}
int main()
{
    test01();
    
    system("pause");
	return 0;
 } 
