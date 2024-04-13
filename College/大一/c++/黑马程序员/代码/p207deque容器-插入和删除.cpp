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
	
	//尾插 
    d1.push_back(10);
	d1.push_back(20);
	
	//头插
	d1.push_front(100);
	d1.push_front(200); 
	printDeque(d1);
	
//	//尾删
//	d1.pop_back();
//	printDeque(d1);
//	
//	//头删
//	d1.pop_front();
//	printDeque(d1);
	
    //insert插入
	d1.insert(d1.begin(),2,1000);
	printDeque(d1);
	
	//按照区间的方式进行插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);
	
	
	//删除
	deque<int>::iterator it=d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);
	
	//按照区间的方式进行删除
	//d1.erase(d1.begin(),d1.end());
	//清空
	d1.clear();
	printDeque(d1); 
}

int main()
{
	test01();
	return 0;
}
