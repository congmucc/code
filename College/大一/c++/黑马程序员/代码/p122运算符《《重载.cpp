#include<iostream> 
using namespace std;
#include<string>


class Person {
	public : 
	    int mAge;
	    string mName;
	
}; 

ostream& operator<<(ostream &cout, Person &p) {
	cout << "���䣺 " << p.mAge << "\n������" << p.mName; 
	return cout;
}

void test01() {
	Person p;
	p.mAge = 10;
	p.mName = "С��";
	
	cout << p <<endl; 
}

int main() {
	
	test01();
	return 0;
}
