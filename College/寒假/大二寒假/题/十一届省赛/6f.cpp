#include<bits/stdc++.h>

using namespace std;

int f[10007], n;

double a = 0, b = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		if (f[i] >= 60) a++;
		if (f[i] >= 85) b++;
	}
	cout << int((a/n + 0.005) * 100)<< "%" << endl;
	cout << int((b/n + 0.005) * 100) << "%";
	
	
	/*
	7
80
92
56
74
88
100
0
	*/
	return 0;
} 
