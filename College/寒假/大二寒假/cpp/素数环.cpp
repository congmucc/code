#include<iostream>

using namespace std;

const int N = 1024;

void print(int n, int a[N]) {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}

//bool prime(int n) {
//	if (n == 1 || n == 2) {
//		return true;
//	}
//	int isPrime[N] = {0};
//	for (int i = 2; i <= n; i++) {
//		if (!isPrime[i]) {
//			for (int j = 2; i * j < n; j++) {
//				isPrime[i * j] = 1;
//			}
//		}
//	}
//	if (isPrime[n] == 0) {
//		return true;
//	} else {
//		return false;
//	}
//}

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


bool check(int k, int a[N], int p, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == k || !prime(a[p - 1] + k)) return false;
	}
	return true;
}
void dfs(int n, int a[N], int t) {
	if (t == n && prime(a[n - 1] + a[0])) {
		print(n, a);
		return;
	}
	
	for (int i = 2; i <= n; i++) {
		if (check(i, a, t, n)) {
			a[t] = i;
			dfs(n, a, t + 1);
			a[t] = 0;
		}
	}
}

int main() {
	int n;
	
	cin >> n;
	
	int a[N] = {0};
	
	a[0] = 1;
	dfs(n, a, 1);
	
	return 0;
}
