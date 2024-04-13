#include<iostream>
using namespace std;


int main() {
	int a = 10;
	
	const int *p = &a;
	
	int b = 20;
	
	p = &b;
	cout<<*p<<endl; 
	
	
	return 0;
} 
