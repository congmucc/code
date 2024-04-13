#include<iostream>
using namespace std;
#include<vector>


void test01()
{
	vector<int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	//使用[]方式访问数组元素 
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	
	//使用at方式访问元素
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	} 
	cout<<endl;
	
	
	//获取他的第一个元素
	cout<<"第一个元素为： "<<v1.front()<<endl;
	//获取最后一个元素
	cout<<"最后一个元素为： "<<v1.back()<<endl; 
}


int main()
{
	test01();
	return 0;
}
