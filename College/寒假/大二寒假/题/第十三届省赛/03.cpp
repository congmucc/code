#include<iostream>

using namespace std;

typedef long long ll;


int main() {
	ll sum = 0;
	ll a, b, n;
	cin >> a >> b >> n;
	while (n) {
		for (int i =1; i <= 5; i++) {
			if (n <= 0) {
				break;
			}
			n -= a;
			sum++;
		}
		if (n <= 0) {
				break;
			}
		for (int i = 1; i <= 2; i++) {
			if (n <= 0) {
				break;
			}
			n -= b;
			sum++;
		}
		if (n <= 0) {
				break;
			}
	}
		cout  << "×Ô¼ºµÄ£º"<< sum;
	
	return 0;
}
