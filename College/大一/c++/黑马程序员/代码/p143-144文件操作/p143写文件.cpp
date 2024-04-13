#include<iostream>
using namespace std;
#include<fstream>

void test01()
{
	ofstream ofs;
	ofs.open("p143test.txt",ios::out);
	ofs<<"ÐÕÃû£ºÕÅÈý"<<endl;
	ofs.close(); 
}

int main()
{
	test01();
	return 0;
}
