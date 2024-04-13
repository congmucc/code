#include<bits/stdc++.h>

using namespace std;

const int N = 3e7;

int f[N];

int main() {
	int n = 20190324;
	f[0] = f[1] = f[2] =1;
	for (int i= 3; i < n; i++) {
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) %10000;
	}
	cout << f[n- 1];
	
	return 0;
} 
