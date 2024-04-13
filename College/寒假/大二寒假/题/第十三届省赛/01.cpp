#include<iostream>

using namespace std;

int main() {
	int x= 2022;
	int a = 1; 
	int res = 0;
	while(x) {
		res += (x%10) * a;
		a = a* 9;
		x /= 10;
	}
	
	cout << res;
	return 0;
} 
