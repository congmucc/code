#include<iostream>
using namespace std;
#include<string>


void test01()
{
	
//string(); //����һ���յ��ַ��� ����: string str;
//string(const char* s); //ʹ���ַ���s��ʼ��
//string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
//string(int n, char c); //ʹ��n���ַ�c��ʼ��
	
	string s1;//Ĭ�Ϲ���
	
	const char *str = "Hello World";
	string s2(str);
	
	cout<<"s2= "<<s2<<endl;
	
	string s3(s2);
	cout<<"s3= "<<s3<<endl;
	
	string s4(10,'a');
	cout<<"s4= "<<s4<<endl;
	
}

 int main()
 {
 	test01();
 	return 0;
 }
