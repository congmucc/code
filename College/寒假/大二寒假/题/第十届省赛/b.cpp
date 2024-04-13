#include<bits/stdc++.h>

using namespace std;

int main() {
	int n = 2019;
	char res[5];
	int p = 0;
	while (n) {
		int k = n %26;
		res[p++]=char(char(k) + 64);
		n /= 26;
	}
	for (int i= p - 1; i >= 0; i--) cout << res[i];
	return 0;
} 
