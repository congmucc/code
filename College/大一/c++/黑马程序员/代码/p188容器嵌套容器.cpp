#include<iostream>
using namespace std;
#include<vector>


void test01()
{
	vector< vector<int> >v;
	
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;
	
	for(int i=1;i<=4;i++)
	{
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
		v5.push_back(i+5);
	}
	
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	
	for(vector< vector<int> >::iterator it=v.begin();it!=v.end();it++)
	{
	     //*it是<>里面的数据类型
		for(vector<int>::iterator its=(*it).begin();its!=(*it).end();its++)
		{
			//别忘了* 返回的是一个地址，要解地址 。 
			cout<<*its<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	test01();
	return 0;
 } 
