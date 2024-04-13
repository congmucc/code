#include<bits/stdc++.h>

#include<map> 

using namespace std;

const int N = 5e4+100;

typedef long long ll;

typedef struct Boom {
	int x, y, r;
}boom; 
boom b1[N], b2[N];

bool vis[N];
map<pair<int, int>,vector<int>>mp;
vector<int>node[N];


int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> b1[i].x >> b1[i].y >> b1[i].r;
		mp[{b1[i].x, b2[i].y}].push_back(i);
	}
	
	
	for (int i = 0; i < m; i++) 
		cin >> b2[i].x >> b2[i].y >> b2[i].r;
		
	dfs();
	
	
	return 0;
} 
