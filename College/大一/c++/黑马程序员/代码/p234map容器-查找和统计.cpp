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
    
    map<int,int>::iterator pos=m1.find(3);//��Ϊfind���ص���һ������������Ҫ��һ��������������
	
	if(pos!=m1.end())
	{
		cout<<"�鵽��Ԫ��  key= "<<(*pos).first<<" value= "<<pos->second<<endl; 
	 } 
	 else
	 {
	 	cout<<"δ�ҵ�Ԫ��"<<endl;
	 }
	 
	 //ͳ��
	 int num=m1.count(3);  //count()���ص�ֵ�ҵ�Ϊ1��δ�ҵ�Ϊ0
	 //��multimap���ص�ֵ����1 
	 map 
	 cout<<"num="<<num<<endl; 
	 
	 
}


int main()
{
	test01();
	return 0;
 } 
