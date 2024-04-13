#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>&l)
{
	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	//创造list容器 
	list<int>l1;
	
	//添加数据
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
    
    if (l1.empty())
    {
    cout << "L1为空" << endl;
    }
    else
    {
    cout << "L1不为空" << endl;
    cout << "l1的大小为： " << l1.size() << endl;
    }
    //重新指定大小
    l1.resize(10,3);
    printList(l1);
    l1.resize(2);
    printList(l1);	
}

int main()
{
	test01();
	return 0;
 } 
