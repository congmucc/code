#include<iostream>
using namespace std;
#include<string>


void test01()
{
	string str="hello";
    
    string subStr=str.substr(1,3);
	cout<<"subStr= "<<subStr<<endl; 
}

//ÊµÓÃ²Ù×÷

void test02() 
{
	string email="zhangsan@qq.com";
	int pos=email.find("@");
	cout<<pos<<endl;
	
	string useName=email.substr(0,pos);
	cout<<useName<<endl;
	
 } 

int main()
{
	test01();
	test02();
	return 0;
} 
