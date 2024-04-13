#include<bits/stdc++.h> 
#include <numeric>
using namespace std;

int gcd(int a, int b) {
	int c = a; 
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int ant = 0;
	
	for (int i = 1; i<= 2020; i++) {
		for (int j = 1; j <= 2020; j++) {
			if (gcd(i, j)) ant ++;
		}
	}
	
	cout << ant;
	return 0;
}
