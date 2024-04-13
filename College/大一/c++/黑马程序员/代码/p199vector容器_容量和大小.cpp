#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int> &v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}



void test01()
{
    vector<int>v1;
//    
//    for(int i=0;i<10;i++)
//    {
//    	v1.push_back(i);
//	}
//    
    printVector(v1);
    
    if(v1.empty())
    {
    	cout<<"v1为空"<<endl;
        cout<<v1.empty()<<endl; 
	}
	else
	{
		cout<<"v1不为空"<<endl;
		cout<<"v1的容量为： "<<v1.capacity()<<endl;
		cout<<"v1的大小是： "<<v1.size()<<endl;
	}
     
    v1.resize(15,100);//利用重载版本，可以指定默认填充值，参数2
    printVector(v1);//如果重载指定的比原来长了，默认用0来填充新的位置 
    
    v1.resize(5);
	printVector(v1);//如果重新指定的比原来短了，超出的部分会删除 
    
}


int main()
{
	test01();
	return 0;
}
