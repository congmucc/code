#include<iostream>
using namespace std;
#include<string>


void test01()
{
	string str="hello";
	
	//通过[]访问单个字符 
    for(int i=0;i<str.size();i++)
	{
		cout<<str[i]<<" ";
	}
	cout<<endl;
	//通过at的方式访问单个字符
	for(int i=0;i<str.size();i++)
	{
		cout<<str.at(i)<<" ";
	}
	cout<<endl;
	
	//修改单个字符
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
