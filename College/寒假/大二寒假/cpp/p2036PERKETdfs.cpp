#include<bits/stdc++.h>

using namespace std;

const int N = 17;
typedef long long ll;

int n, s[N], b[N], f[N];

ll sum1 = 1, sum2 = 0, cut = 1e10;

void dfs(int l) {
	if (l >= n) {
		
	}
	else
	for (int i = l; i < n; i ++) {
		if (f[i] == false) {
		sum1 *= s[i];
		cout  << "µÚ" << l << "´Î£º"<< sum1 << "\t";
		sum2 += b[i];
		cout  << sum2 << endl;
		cut = min(abs(sum1 - sum2), cut);
		f[i] = 1;
		dfs(l + 1);
		f[i] = 0;
		sum1 /= s[i];
		sum2 -= b[i];
	}
	}
}
 
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> b[i];
	}
	dfs(0);
	cout << cut;
	return 0;
} 
