#include<iostream>
using namespace std;
#include<string>


void test01()
{
	string str="hello";
	
	//ͨ��[]���ʵ����ַ� 
    for(int i=0;i<str.size();i++)
	{
		cout<<str[i]<<" ";
	}
	cout<<endl;
	//ͨ��at�ķ�ʽ���ʵ����ַ�
	for(int i=0;i<str.size();i++)
	{
		cout<<str.at(i)<<" ";
	}
	cout<<endl;
	
	//�޸ĵ����ַ�
	str[0]='x';
	cout<<"str="<<str<<endl;
	str.at(1)='x';
	cout<<"str="<<str<<endl;              
	 
}

int main()
{
	test01();
	return 0;
} 
