#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test01()
{
	ifstream ifs;
	ifs.open("p143test.txt",ios::in);
	if(!ifs.is_open() )
	{
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
//��һ�ֶ�д���� 
//	char buf[1024]={0};
//	while(ifs>>buf)
//	{
//		cout<<buf<<endl;
//	}

//�ڶ��ַ���
//  char buf[1024]={0};
//	while(ifs.getline(buf,sizeof(buf)))
//	{
//		cout<<buf<<endl;
//  } 

//�����ַ���
    string buf; 
    while(getline(ifs,buf))
	{
		cout<<buf<<endl;
	} 
}

int main()
{
	test01(); 
	return 0;
}
