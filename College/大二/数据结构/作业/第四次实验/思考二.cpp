#include<iostream>

using namespace std;

#include<queue>

const int M = 8, N = 8; 




typedef struct Q {
    int x, y;
}Qn;

queue<Qn> result;

Qn pre[M + 2][N + 2];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, 1};

void bfs(int mg[M + 2][N + 2], Qn q) {
    result.push(q);
    mg[q.x][q.y] = 1;
    
	while (result.size()) {
		auto u = result.front();
		 result.pop();
    	for (int i = 0; i < 4; i++) {
    		Qn dq;
    		dq.x = u.x + dx[i], dq.y = u.y + dy[i];
    		if (dq.x < 1 || dq.x >= 9 || dq.y < 1 || dq.y >= 9) continue;
    		if (mg[dq.x][dq.y]) continue;
			mg[dq.x][dq.y] = 1;
			pre[dq.x][dq.y] = u;
			result.push(dq);
		}
	}
}

void print(int x, int  y) {
	if (x== 0 && y == 0) return;
	Qn p = pre[x][y];
	print (p.x, p.y);
    cout << "{" << x << ", " << y << "}" << endl; 
}

int main () {
	int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
    Qn q;
	
	q.x = 1, q.y = 1;
	
	
	bfs(mg, q);
	
	cout << "µ¹ÐðÂ·¾¶ÈçÏÂ£º" << endl; 
    
    print(8, 8); 
	return 0;
} 
