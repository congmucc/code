#include<bits/stdc++.h> 
using namespace std;
const int N=100030;
int a[N],b[N], c[N];

const int mod = 1e9 + 7;
typedef long long ll;
int main()
{
	int N;
	cin >> N;
	 
    int A, B;
	cin >> A;
    for (int i = 0; i < A; i++) {
    	cin >> a[i];
	}
	
	cin >> B;
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
    int len = A;
    for (int i = 1; i <= len; i++) {
    	c[i] = 2;
    	c[i] = max(c[i], max(a[i], b[i]) + 1); 
	}
	ll ansA = 0, ansB = 0;
	for (int i = 1; i <= len; i++) {
		ansA = (ansA * c[i] + a[i]) % mod;
		if (i <= B) ansB = (ansB * c[i] + b[i]) % mod;
	}
	ll ans = (ansA - ansB + mod) % mod;
	cout << ans << endl;
	
	return 0;
}
