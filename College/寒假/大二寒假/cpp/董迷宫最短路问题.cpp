#include<bits/stdc++.h>
#include<queue>

using namespace std;

const int N = 1e4;
typedef pair<int, int> PII;
queue<PII> q;

/*
5
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/

int n, m;
int g[N][N], dist[N][N] = {0};
PII pre[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void bfs(int x, int  y) {
	memset(dist, 0, sizeof dist);
	q.push({x, y});
	dist[x][y] = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a >= n || a < 0 || b < 0 || b >= m) continue;
			if (dist[a][b]) continue;//走过的路
			if (g[a][b]) continue;//墙 
			dist[a][b] = dist[t.first][t.second] + 1;
			pre[a][b] = t;
			q.push({a, b});
			
		}
	}
}


void print(int x, int y) {
	if (x == 0 && y == 0) return;
	PII p = pre[x][y];
	print(p.first, p.second);
	printf("%d %d\n", x, y);
}

int main() {


	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j ++) {
			cin >> g[i][j];
		}
	}
	bfs(0, 0);
	printf("0 0\n");
    print(n - 1, n - 1); 
	
	return 0;
} 
