#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod=1e9+7;
const int N = 113;
ll ans = 0;

int f[N][N][N];
void dp() {
	int n, m;
	cin >> n >> m;
	f[0][0][2] = 1;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m; k++) {
				if (j) f[i][j][k] = (f[i][j - 1][k + 1] + f[i][j][k]) % mod;
				if (i && k % 2 == 0)  f[i][j][k] = (f[i - 1][j][k / 2] + f[i][j][k]) % mod;
			}
		}
	}
	
	cout << f[n][m - 1][1] << endl;
}


void dfs(int c,int n,int m,int step) {
	if (n == 0 && m == 0 && c == 1) ans++;
	
	if (n > 0) {
		dfs(c * 2, n - 1, m, step + 1);
	}
	
	if (m > 0) {
		dfs(c - 1, n, m - 1, step + 1);
	}
}

int main() {
	
	//dp();
	
	//dfsÐ´·¨£¬ ³¬Ê±
	int n, m;
	cin >> n >> m;
	dfs(2, n, m - 1, 1);
	
	cout << ans %mod << endl; 
	
	return 0;
}
