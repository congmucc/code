#include<iostream>
using namespace std;
#include<string>




void test01()
{
    string str1="abcdefg";
	int pos = str1.find("de");
	if(pos==-1)
	{
		cout<<"δ�ҵ��ַ���"<<endl; 
	}
	else
	{
		cout<<"�ҵ��ַ���,pos= "<<pos<<endl; 
	}
	
	//rfind��find������
	//rfind���������    find�������Ҳ� 
	
	pos=str1.rfind("de");
	
	cout<< "pos="<<pos<<endl;
	
	//�滻
	
	str1.replace(1,3,"111");
	cout<<str1<<endl; 
	str1.append("111",3);
	cout<<str1<<endl; 
}


int main()
{
	test01();
	return 0;
}
