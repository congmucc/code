#include<iostream> 
using namespace std;
#include<string>


class Person {
	public : 
	    int mAge;
	    string mName;
	
}; 

ostream& operator<<(ostream &cout, Person &p) {
	cout << "ÄêÁä£º " << p.mAge << "\nÐÕÃû£º" << p.mName; 
	return cout;
}

void test01() {
	Person p;
	p.mAge = 10;
	p.mName = "Ð¡ºì";
	
	cout << p <<endl; 
}

int main() {
	
	test01();
	return 0;
}
