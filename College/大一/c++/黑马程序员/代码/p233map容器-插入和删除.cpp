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
	
	//插入
	//第一种 
	m1.insert(pair<int,int>(1,10));
    //第二种     更好自动识别 
	m1.insert(make_pair(2,20));
	//第三种
	m1.insert(map<int,int>::value_type(3,30));
	//第四种   不建议，容易插错  如m1[5]=0，不过也可以通过if(!m[5])来判别             用途  可以利用key访问到value  如cout<<m1[4]<<endl; 
	m1[4]=40; 
	
	m1[5];
	
	printMap(m1);
	
	//删除 
	
	cout<<"删除后："<<endl;
	m1.erase(m1.begin());
	printMap(m1);
	
	
	cout<<"key删除后："<<endl;
	m1.erase(3);  //按照key删除 
	printMap(m1);
    
    m1.clear();
    printMap(m1);
}


int main()
{
	test01();
	return 0;
 } 
