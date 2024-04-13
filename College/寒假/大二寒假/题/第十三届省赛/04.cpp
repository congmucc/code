
#include<iostream>
using namespace std;
typedef long long ll;
 
int a[10009] = {0};
int cnt[10009] = {0};

int main() {
	int N;
	cin >> N;
	int r; 
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) a[j]++;
		if (cnt[i] <= a[i]) cnt[i] = a[i];
		a[i] = 0;
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) a[j]++;
		if (cnt[i] <= a[i]) cnt[i] = a[i];
		a[i] = 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) a[j]++;
		if (cnt[i] <= a[i]) cnt[i] = a[i];
		a[i] = 0;
	}
	
	for (int i = 0; i < N; i++) {
		cnt[i]--; 
		cout << cnt[i] << endl;
	}
	return 0;
}
