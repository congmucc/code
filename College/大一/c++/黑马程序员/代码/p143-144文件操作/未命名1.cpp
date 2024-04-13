#include<iostream>
using namespace std;
#include<fstream>

void test01()
{
	ifstream ifs;
	ifs.open("p143test.txt", ios::in);
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
	    return; 
	}
	
	char buf[1000]={0};
	while(ifs>>buf)
	{
		cout<<buf<<endl;
	}
	ifs.close();
}

int main()
{
	test01();
	return 0; 
}

