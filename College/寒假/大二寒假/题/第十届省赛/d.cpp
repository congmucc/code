#include<bits/stdc++.h>

using namespace std;

const int N = 3e7;

int f[N];

bool check(int n) {
	while (n) {
		int k = n % 10;
		n /= 10;
		if (k == 2 || k == 4) return false;
	}
	return true;
}


int main() {
	int n = 2019, ans = 0;
	for (int i = 1; i  < n; i++) {
		if (check(i)) 
		    for (int j = i + 1; j < n; j ++) {
		    	if (check(j)) {
		    		int k = n - i - j;
		    		if (check(k) && k > j) ans++;
				}
		    	    
			}
		
	}
	cout << ans;
	return 0;
} 
