#include<iostream> 
using namespace std;

class myClass
{
public :
    myClass();// ���캯�����޷������ͣ������в����б�����ʡȥ
    
    int a = 1;
    int b = 1;
};


myClass::myClass():b(1),a(b)
{
	
}

int main() {
	myClass a;
	cout<<a.a<<endl;
	cout<<a.b<<endl;
	cout<<a.a<<endl;
	cout<<a.b<<endl;
	return 0;
}

