#include<bits/stdc++.h>

using namespace std;

int main() {
	int k = 0, j = 1;
	
	for (int i= 1; i < 2020; i++) {
		cout << i << " ";
		k++;
		if (k == j) {
			cout <<endl;
			j ++;
			k = 0;
		}
	}
	
	//761
	return 0; 
}
