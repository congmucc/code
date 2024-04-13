#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
 };

class MyPrint
{
public:
    void operator()(int val)
    {
    	cout<<val<<" ";
	}
};

void test01()
{
	vector<int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	
	vector<int>v2;  //  Ŀ������
	
	v2.resize(v1.size()); // Ŀ��������Ҫ��ǰ���ٿռ� 
	  
	
	transform(v1.begin(),v1.end(),v2.begin(),Transform());
	
	for_each(v2.begin(),v2.end(),MyPrint());
	cout<<endl;
}

int main()
{
	test01();
	return 0;
 } 
