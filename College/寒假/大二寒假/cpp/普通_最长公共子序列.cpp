#include<iostream>

using namespace std;

const int N = 1e2+10;

int main() {
	int n;
	cin >> n;
	int arr1[N]{0}, arr2[N]{0};
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int j = 0; j < n; j++) cin >> arr2[j];
	
	int dp[N + 1][N + 1]{0};
    
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			cout << dp[i][j] << " "; 
		}
		cout << endl;
	}
	cout << dp[n][n] <<endl;
	return 0;
}

