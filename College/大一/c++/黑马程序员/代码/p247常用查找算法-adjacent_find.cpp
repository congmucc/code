#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(10);
	
	
	vector<int>::iterator it=adjacent_find(v.begin(),v.end());  //���������ظ�Ԫ�� 
	
	cout<<*it<<endl;
}


int main()
{
	test01();
	return 0;
 } 
