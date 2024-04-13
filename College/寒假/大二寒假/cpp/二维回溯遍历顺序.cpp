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


void print(int board[N][N], int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void solveNQueens(int board[N][N], int n, int k) {
	if (k == n) {
		return;
	}
	//先遍历第一列，之后遍历第二列。 
	for (int i = 0; i < n; i++) {
		    board[k][i] = result++;
		    print (board, n);
		    solveNQueens(board, n, k + 1);
		    board[k][i] = 0;
	}
}

int main() {
	int n;
	
	n = 4;
	
    int board[N][N] ={0};
	
	solveNQueens(board, n, 0);
	

	return 0;
} 
