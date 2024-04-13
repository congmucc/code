#include<bits/stdc++.h>

using namespace std;
 
int gcd(int a, int b) {
	int c = b;
	while (a%b) {
		c= a%b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int n,f[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	
	sort(f, f+n);
	int ant = f[1] - f[0];
	
	for (int i = 0; i < n; i++) {
		ant = gcd(ant, f[i] - f[i - 1]);
	//	ant = __gcd(ant, f[i] - f[i - 1]);
	}
	cout << (f[n - 1] - f[0])/ant + 1<<endl;
	
	return 0;
} 
