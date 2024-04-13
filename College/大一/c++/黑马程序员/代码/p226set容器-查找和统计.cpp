#include<iostream>
using namespace std;
#include<set>

void test01()
{
	set<int>s1;
	
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	
	set<int>::iterator pos=s1.find(30);
	
	if(pos!=s1.end())
	{
		cout<<"找到元素"<<endl; 
	 } 
	else
	{
		cout<<"未找到元素"<<endl; 
	}
	
	int num=s1.count(30);
	cout<<num<<endl; 
}


int main()
{
	test01();
	return 0;
 } 
