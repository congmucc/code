#include<iostream> 
using namespace std;

class myClass
{
public :
    myClass();// 构造函数，无返回类型，可以有参数列表，这里省去
    
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

