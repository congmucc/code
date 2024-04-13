#include<iostream>

using namespace std;

const int N = 14;

int result = 0;
void printBoard(int board[N][N], int n) {
	if (result >= 3) return;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++ ) {
			if (board[i][j] == 1) cout << j + 1 << " " ;
		}
	}
	cout << endl;
}

//i 是列， k 是行 
bool check(int board[N][N], int n, int i, int k) {
	// 对于列
	for (int j = 0; j < k; j++) {
		if (board[j][i] == 1) return false;
	}
	// 对于45度
	for (int a = k - 1, b = i - 1; a >= 0 && b >= 0; a--, b--) {
		if (board[a][b] == 1) return false;
	} 
	// 对鱼135度
	for (int a = k - 1, b = i + 1; a >= 0 && b < n; a--, b++) {
		if (board[a][b] == 1) return false;
	}
	
	return true;
}


void solveNQueens(int board[N][N], int n, int k) {
	if (k == n) {
		printBoard(board, n);
		result++;
		return;
	}
	//先遍历第一列，之后遍历第二列。 
	for (int i = 0; i < n; i++) {
		if (check(board, n, i, k)) {
		    board[k][i] = 1;
		    solveNQueens(board, n, k + 1);
		    board[k][i] = 0;
		}
	}
}

int main() {
	int n;
	
	cin >> n;
	
    int board[N][N] ={0};
	
	solveNQueens(board, n, 0);
	
	cout << result;
	return 0;
} 
