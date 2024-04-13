#include<bits/stdc++.h>

using namespace std; 

int main() {
	
	int res = 0;
	
	for (int i = 1; i < 2021; i++) {
		int k = i;
		while(k) {
			int j = k %10;
			if (j  == 2) res++;
			k = k /10;
		}
	} 
	
	cout << res << endl;
	
	return 0;
} 
