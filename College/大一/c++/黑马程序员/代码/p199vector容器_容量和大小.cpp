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
    	cout<<"v1Ϊ��"<<endl;
        cout<<v1.empty()<<endl; 
	}
	else
	{
		cout<<"v1��Ϊ��"<<endl;
		cout<<"v1������Ϊ�� "<<v1.capacity()<<endl;
		cout<<"v1�Ĵ�С�ǣ� "<<v1.size()<<endl;
	}
     
    v1.resize(15,100);//�������ذ汾������ָ��Ĭ�����ֵ������2
    printVector(v1);//�������ָ���ı�ԭ�����ˣ�Ĭ����0������µ�λ�� 
    
    v1.resize(5);
	printVector(v1);//�������ָ���ı�ԭ�����ˣ������Ĳ��ֻ�ɾ�� 
    
}


int main()
{
	test01();
	return 0;
}
