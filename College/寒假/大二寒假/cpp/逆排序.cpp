#include<bits/stdc++.h>

using namespace std;

int  a[10]; 

bool comp(int i, int j) {
	return i > j;
}

int main() {
	
	for (int i = 10; i > 0; i--) a[i] = i;
	//Ä¬ÈÏÉıĞò 
	sort(a, a+10);
	
	for (int i = 0; i < 10; i++) cout << a[i] << " "; 
	
	cout << endl;
	
	sort(a, a+10, comp);
	
	for (int i = 0; i < 10; i++) cout << a[i] << " "; 
	return 0;
} 
