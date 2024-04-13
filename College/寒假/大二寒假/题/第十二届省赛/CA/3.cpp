#include<iostream>
#include<stdio.h>

using namespace std;

#include<vector>


int main() {
	long long n = 2021041820210418;
	long long sum = 0;
	vector<long long> a;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			a.push_back(i);
		if (n / i != i) a.push_back(n / i);
		} 
	}
	int i, j, k; 
	for (i = 0; i < a.size(); i++) {
		for (j = 0; j < a.size(); j++) {
			for (k = 0; k < a.size(); k++) {
				if (a[i] * a[j] * a[k] == n) sum++;
			}
		}
	}

	cout << sum << endl;
	
	return 0;
} 
