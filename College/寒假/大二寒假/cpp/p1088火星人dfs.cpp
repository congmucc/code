#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4;

int n, m, f[N], flag, flagx;
bool s[N];

void dfs(int t) {
	if (flagx == 1) return;
	if (t == n) {
		flag++;
		if (flag == m + 1) {
		for (int i = 0; i < n - 1; i++) {
			cout << f[i] << " ";
		}
		cout << f[n - 1];
		flagx = 1;
	    }
	    return;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag) {
			i = f[t];
		}
		if (s[i] == true) continue;
		s[i] = true;
		f[t] = i;
		dfs(t + 1);
		s[i] = false;
	}
}


int main() { 
	cin >> n >> m;
	for (int i = 0; i < n; i++ )
	    cin >> f[i];
	dfs(0);
	
	return 0;
} 
