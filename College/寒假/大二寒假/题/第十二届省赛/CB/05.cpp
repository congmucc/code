#include<iostream>
using namespace std;


const int N = 2030;

int f[N];

int lcm(int a, int b) {
	int c = 0, d = a, e = b;
	while (a%b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return (d * e) / c;
}
 

int main() {
	
	for (int i = 1; i <= 2021; i++) {
		for (int j = i + 1; j <= 2021; j++) {
			if (j - i <= 21) {
				int a = lcm(i, j);
				if (f[j] == 0)f[j] = f[i] + a;
				else f[j] = min(f[i] + a, f[j]);
			}
		}
	}
	cout << f[2021] << endl;
	
	
	return 0;
} 
