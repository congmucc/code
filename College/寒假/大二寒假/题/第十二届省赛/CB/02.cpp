#include<iostream>

#include<cstring>
using namespace std;



int ans[10];

int main() {
	for (int i = 0; i < sizeof(ans)/sizeof(ans[0]); i++) 
		ans[i] = 2021;
	int s = 1;
	int k;
	int a, b;
	while (1) {
		k = s;
		while (k) {
			a = k % 10;
			
			if (ans[a] > 0)ans[a]--;
			else break;
			
		    k = k / 10;
		}
		if (k > 0) break;
		else s++;
	}
	
	cout << s;
	
	return 0;
}
