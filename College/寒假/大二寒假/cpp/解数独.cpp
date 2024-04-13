#include<iostream>

using namespace std;


bool check(int board[9][9], int x, int y, int k) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == k || board[i][y] == k)  {
			return false;
		}
	} 
	int test[] = {0, 3, 6};
	int left = test[x / 3];
	int right = test[y / 3];
	for (int i = left; i < left + 3; i++) {
		for (int j = right; j < right + 3; j++)
		{
			if (board[i][j] == k)
				return false;
		}
	}
	return true;
}

void dfs(int board[9][9], int x, int y) {
	if (x == 9) {
		for (int i = 0; i < 9; i++)//Êä³ö
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		return ;
	}
	
	if (board[x][y] == 0) {
		for (int i = 1; i <= 9; i++){
			if (check(board, x, y, i)) {
			    board[x][y] = i;
			    dfs(board, x + (y + 1) / 9, (y + 1) % 9);
			}
		}
		board[x][y] = 0;
	} else {
		dfs(board, x + (y + 1) / 9, (y + 1) % 9);
	}
}

int main() {
    int board[9][9] = {
	{0,0,5,3,0,0,0,0,0},
	{8,0,0,0,0,0,0,2,0},
	{0,7,0,0,1,0,5,0,0},
	{4,0,0,0,0,5,3,0,0},
	{0,1,0,0,7,0,0,0,6},
	{0,0,3,2,0,0,0,8,0},
	{0,6,0,5,0,0,0,0,9},
	{0,0,4,0,0,0,0,3,0},
	{0,0,0,0,0,9,7,0,0} 
	};
	
	dfs (board, 0, 0);

	return 0;
}
