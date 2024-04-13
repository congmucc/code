#include<bits/stdc++.h>

using namespace std;

int m[1001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
bool vis[1001];
int n;

int ans = 0;

int k[3];
void dfs(int sum, int p) {
	if (p > 2) {
		if (k[0] + k[1] == k[2] && sum == n) ans++;
		return;
	}
	
	for (int i = 0; i <= 999; i++) {
		sum += m[i];
		k[p] = i;
		dfs(sum, p + 1);
        sum -= m[i];
	}
}

int main() {
	cin >> n;
	for (int i = 10; i <= 999; i++) {
		m[i] = m[i / 10] + m[i % 10];
	}
	dfs(4, 0);
	cout << ans;
	return 0;
}
