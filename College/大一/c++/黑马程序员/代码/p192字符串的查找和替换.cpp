#include<iostream>
using namespace std;
#include<string>




void test01()
{
    string str1="abcdefg";
	int pos = str1.find("de");
	if(pos==-1)
	{
		cout<<"Î´ÕÒµ½×Ö·û´®"<<endl; 
	}
	else
	{
		cout<<"ÕÒµ½×Ö·û´®,pos= "<<pos<<endl; 
	}
	
	//rfindºÍfindµÄÇø±ð
	//rfind´ÓÓÒÍù×ó²é    find´Ó×óÍùÓÒ²é 
	
	pos=str1.rfind("de");
	
	cout<< "pos="<<pos<<endl;
	
	//Ìæ»»
	
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
