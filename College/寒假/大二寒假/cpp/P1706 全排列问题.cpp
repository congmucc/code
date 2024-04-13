#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5;

vector<int> v;
vector<bool> b(N,false); 

void dfs(int n) {
	if (v.size() == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << "    " << v[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == true) continue;
		v.push_back(i);
	    b[i] = true;
		dfs(n);
		v.pop_back();
		b[i] = false;
	}
}


int main() {
	int n;
	cin >> n;
	dfs(n);
	return 0;
} 
