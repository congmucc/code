#include<bits/stdc++.h>

using namespace std;

int n, a[10000][10], b[10], res = 0;

void dfs(int t, int k) {
	if (k == 10) {
		if (t == n) {
			for (int i = 0; i < 10; i++) a[res][i] = b[i];
			res++; 
		}
	}
	else if (t >= n) return;
	else
	for (int i = 1; i <= 3; i ++) {
		b[k] = i;
		dfs(t + i, k + 1);
	}
}

int main() {
	
	cin >> n; 
	if (n > 30) cout << 0;
	else dfs(0, 0);
	cout << res <<endl;
	for (int j=0;j<res;j++){
      for (int i=0;i<10;i++) cout<<a[j][i]<<" ";
     cout<<endl; 
    }
	return 0;
} 
