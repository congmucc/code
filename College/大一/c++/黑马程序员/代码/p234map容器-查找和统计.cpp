#include<iostream>
using namespace std;
#include<map> 
void printMap(map<int,int>&m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"key= "<<(*it).first<<"   "<<"value= "<<it->second<<endl;
	}
}



void test01()
{
	map<int,int>m1;
	
	m1.insert(make_pair(1,10));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,30));
    m1.insert(make_pair(4,40));
    
    printMap(m1);
    
    map<int,int>::iterator pos=m1.find(3);//因为find返回的是一个迭代器，故要用一个迭代器来接收
	
	if(pos!=m1.end())
	{
		cout<<"查到了元素  key= "<<(*pos).first<<" value= "<<pos->second<<endl; 
	 } 
	 else
	 {
	 	cout<<"未找到元素"<<endl;
	 }
	 
	 //统计
	 int num=m1.count(3);  //count()返回的值找到为1，未找到为0
	 //但multimap返回的值大于1 
	 map 
	 cout<<"num="<<num<<endl; 
	 
	 
}


int main()
{
	test01();
	return 0;
 } 
