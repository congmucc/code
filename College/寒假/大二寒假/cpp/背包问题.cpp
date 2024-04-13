#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e4;

int n, v[N], w[N], V;

int dp[N];

void bagProblem(int w[N], int v[N]) {
	f[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = V; j >= w[i]; j --) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[V];
}


int main() {
	
	cin >> n >> V;
	for (int i = 0;i < n;i ++) {
		cin >> w[i] >> v[i];
	}
	
	bagProblem(w, v);
	
	return 0;
} 
