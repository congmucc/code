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
	
	//����
	//��һ�� 
	m1.insert(pair<int,int>(1,10));
    //�ڶ���     �����Զ�ʶ�� 
	m1.insert(make_pair(2,20));
	//������
	m1.insert(map<int,int>::value_type(3,30));
	//������   �����飬���ײ��  ��m1[5]=0������Ҳ����ͨ��if(!m[5])���б�             ��;  ��������key���ʵ�value  ��cout<<m1[4]<<endl; 
	m1[4]=40; 
	
	m1[5];
	
	printMap(m1);
	
	//ɾ�� 
	
	cout<<"ɾ����"<<endl;
	m1.erase(m1.begin());
	printMap(m1);
	
	
	cout<<"keyɾ����"<<endl;
	m1.erase(3);  //����keyɾ�� 
	printMap(m1);
    
    m1.clear();
    printMap(m1);
}


int main()
{
	test01();
	return 0;
 } 
