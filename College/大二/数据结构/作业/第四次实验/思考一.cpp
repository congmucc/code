#include<iostream>

using namespace std;

#include<stack>

const int M = 8, N = 8; 

typedef struct Q {
    int x, y;
}Qn;

stack<Qn> result;


void dfs(int mg[M + 2][ N + 2], Qn q) {
	if (q.x > 0 && q.y > 0 && q.x < 9 && q.y < 9){
		if (q.x == 8 && q.y == 8) {
		    cout << "找到出口" << endl; 	
		    return;
		}
		
		if (mg[q.x][q.y + 1] == 0 && q.y + 1 < N + 1) {
			q.y++;
			result.push(q);
			dfs(mg, q);
			return;
		}
		if (mg[q.x + 1][q.y] == 0 && q.x + 1 < M + 1) {
			q.x++;
			result.push(q);
			dfs(mg, q);
			return;
		}
		if (mg[q.x][q.y - 1] == 0 && q.y - 1 > 0) {
			mg[q.x][q.y] = 1;
			result.pop();
			q.y--;
			dfs(mg, q);
			return;
		}
		if (mg[q.x - 1][q.y] == 0 && q.x - 1 > 0) {
			mg[q.x][q.y] = 1;
			result.pop(); 
			q.x--;
			dfs(mg, q);
			return;
		}
		
    }
}


int main () {
	int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
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
	result.push(q);
    dfs(mg, q);
    cout << "倒叙路径如下：" << endl; 
    while(!result.empty()) {
    	cout << "{" << result.top().x << ", " << result.top().y << "}" << endl;
    	result.pop();
	}
	
	return 0;
} 
