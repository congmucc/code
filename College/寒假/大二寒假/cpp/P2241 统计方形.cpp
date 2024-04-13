#include<iostream>

using namespace std;

long long m, n, i, j, sum1, sum2;

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			sum1 += min(i, j);
			sum2 += i*j;
		}
	}
	cout<<sum1<<" "<<sum2-sum1<<endl;
	return 0;
} 
