#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>&d)//防止修改 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)//既然形参用了const  迭代器也得用const_iterator!!!! 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


void test01()
{
	deque<int>d1;
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	
	if(d1.empty())
	{
		cout<<"d1为空"<<endl;
	} 
	else
	{
		cout<<"d1不为空"<<endl;
		cout<<"d1的大小为："<<d1.size()<<endl;
		//deque容器没有容量的概念
	}
	
	//重新指定大小
	 d1.resize(15,1);
	 printDeque(d1);
	 
	 d1.resize(5);
	 printDeque(d1);
}

int main()
{
	test01();
	return 0;
}
