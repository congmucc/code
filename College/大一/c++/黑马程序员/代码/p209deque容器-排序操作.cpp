#include<iostream>
using namespace std;
#include<deque>
#include<algorithm> 
void printDeque(const deque<int>&d)
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);
    sort(d.begin(),d.end());
    //排序 默认为从小到大，升序
	//对于支持迭代器的容器，都可以进行sort算法进行直接排序 
    cout<<"排序后"<<endl; 
	printDeque(d);
}

int main()
{
	test01();
	return 0;
}
