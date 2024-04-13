#include<iostream>

using namespace std;

/*
有一个大小为 N*M 的园子，雨后积起了水。八连通的积水被认为是连接在一起的。请求出
园子里总共有多少水洼？（八连通指的是下图中相对 W 的*的部分）

    ***
    *W*
    ***

限制条件

 N, M ≤ 100

 样例:

 输入
    N=10, M=12

园子如下图（'W'表示积水， '.'表示没有积水）

W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.....W...W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

输出

    4

 */


const int N = 1e2+10;
const int M = 1e2+10;



int n, m;

//    https://blog.csdn.net/weixin_43946167/article/details/105412508 

void dfs(char a[N][M], int i, int j) {
	a[i][j] = '.'; 
    for (int k = -1; k < 2; k++) {//-1,0,1   k, i 是多少行 
      for (int l = -1; l < 2; l++) {//-1,0,1   j, l 是多少列 
        if (k == 0 && l == 0) continue;

        if (i + k >= 0 && i + k <= n - 1 && j + l >= 0 && j + l <= m - 1) {
          if (a[i + k][j + l] == 'W')
            dfs(a, i + k, j + l);
        }
      }
    //是否需要回溯，看具体问题，具体解题思路而定！
    }
}

int main() {

	cin >> n >> m;
	char str[N][M];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];
		} 
	}
	
   int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (str[i][j] == 'W') {
		    cnt++; 
            dfs(str, i, j);//清除一个水洼
        }
      }
    }
	cout << cnt << endl;
	return 0;
} 
