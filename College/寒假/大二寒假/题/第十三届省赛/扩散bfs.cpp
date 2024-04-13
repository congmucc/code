#include<bits/stdc++.h>
#include<queue>
using namespace std;

typedef long long ll;

const int N = 10000;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
struct node{
	int x;
	int y;
	int min;//∑÷÷” 
};

bool mp[N][N];

queue<node> q; //∂”¡– 
ll ans=0;

void bfs() {
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.min == 2020) break;
		
		for (int i = 0; i < 4; i++) {
			int a = t.x + xx[i];
			int b = t.y + yy[i];
			if (!mp[a][b]) {
				ans++;
				mp[a][b] = 1;
				q.push({a, b, t.min + 1});
			}
		}
	}
}


int main() {
	
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			mp[i][j]  = false;
		} 
	}
	
	mp[0+2500][0+2500]=1;
	mp[2020+2500][11+2500]=1;
	mp[11+2500][14+2500]=1;
	mp[2000+2500][2000+2500]=1;
	q.push({0+2500,0+2500,0});
	q.push({2020+2500,11+2500,0});
	q.push({11+2500,14+2500,0});
	q.push({2000+2500,2000+2500,0});
	ans=4;
	
	bfs();
    
    cout << ans << endl;
	return 0;
} 
