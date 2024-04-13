#include<iostream>

using namespace std;
 
int main() {
	long long n;
	cin >> n;
	n = n % 86400000;
	n /= 1000;
	int h;
	int m;
	int s;
	
	h = n / (60 *60);
	m = n %(60 *60) / 60;
	s = n % 60;
	printf("%02d:%02d:%02d",h,m,s); 
	return 0;
}
