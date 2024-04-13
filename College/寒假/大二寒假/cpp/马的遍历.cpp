#include<iostream>
using namespace std;
#include<string.h>
#include<queue>

#include<cstdio>


int main() {
	int path[450][450];
    
	memset(path, -1, sizeof(path));
	

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	
	path[x][y] = 0;
	
	int dx[8]={1,2,-1,-2,-1,-2,1,2};
    int dy[8]={2,1,2,1,-2,-1,-2,-1};
    
    queue<pair<int, int>> q;
    
	q.push(pair<int, int>(x, y));
    while (!q.empty()) {
    	for (int i = 0; i < 8; i++) {
    		int newx = q.front().first + dx[i];
    		int newy = q.front().second + dy[i];
    		if (path[newx][newy] == -1 && newx >= 1 && newx <= n && newy >= 1 && newy <= m) {
    			path[newx][newy] = path[q.front().first][q.front().second] + 1;
    			q.push(pair<int, int>(newx, newy));
			}
		}
		q.pop();
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-5d", path[i][j]);
		}
		cout << endl;
	}
	return 0;
}
