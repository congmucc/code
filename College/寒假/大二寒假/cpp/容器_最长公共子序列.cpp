#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> text1(n, 0);
	vector<int> text2(n, 0);
	
	for (int i = 0; i < n; i++) cin >> text1[i];
	for (int j = 0; j < n; j++) cin >> text2[j]; 
	
	
	vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    
	    for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    cout<< dp[n][n];
    return 0;
}
