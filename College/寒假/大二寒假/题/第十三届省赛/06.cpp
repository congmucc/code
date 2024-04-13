#include<bits/stdc++.h>

using namespace std;

const int P = 3e9 + 7;

typedef long long ll;

int N, M, K;
int sum = 0;
int arr[1005][1005];
int cnt = 0;
int pre[1005][1005];


int main() {
	
	
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			pre[i][j] = pre[i][j - 1] + arr[i][j] 
		}
	}
	
	for (int i = 0; i < m; i ++) {
		for (int j =  i + 1; j <= m; j++) {
			int sum = 0;
			for (int r =1 ,l = 1; r <= n; r++) {
				sum += pre[r][j] - pre[r][i];
				//cout << "sum:" << sum << endl;
				while (r >=l&& sum > k) {
					sum -= pre[l][j] - pre[l][i];
					l++;
				} 
				if (r >=l) {
					cnt += r - l + 1;
					//cout<<"cnt:"<<cnt<<endl;
				}	
			}
		}
	}
	
	cout << cnt << endl;
	return 0;
}
