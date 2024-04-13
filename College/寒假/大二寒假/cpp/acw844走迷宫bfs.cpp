#include<bits/stdc++.h>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e4;

int n, m;

queue<PII> q;
int g[N][N];
int dist[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 1, -1};

void bfs(int x1, int y1) {
	memset(dist, -1, sizeof dist);
	
	q.push({x1, y1});
	dist[x1][y1] = 0;
	
	while (q.size() && q.empty()) {
		auto t = q.front();
		q.pop();
		
		for (int i = 0; i < 4;i ++) {
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 0 || a >= n ||b < 0 || b>= m) continue;
			if (g[a][b] != 0) continue;
			if(dist[a][b] > 0) continue;
			q.push({a, b});
			dist[a][b] = dist[t.first][t.second] + 1;
		}
	}
}


int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; i < m; j ++) {
			cin >> g[i][j];
		}
	}
	
	cout << bfs(1, 1);
	return 0;
} 
