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
	//����list���� 
	list<int>l1;
	
	//�������
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
    
    if (l1.empty())
    {
    cout << "L1Ϊ��" << endl;
    }
    else
    {
    cout << "L1��Ϊ��" << endl;
    cout << "l1�Ĵ�СΪ�� " << l1.size() << endl;
    }
    //����ָ����С
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
