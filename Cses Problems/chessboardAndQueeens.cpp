#include<bits/stdc++.h>

using namespace std;

string vec[8];
int res = 0;
int board[8][8];

bool isSafe(int row, int col) {
	if(vec[row][col] == '*') return false;
	
	for(int i = 0; i < col; i++) {
		if(board[row][i]) return false;
	}
	
	for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if(board[i][j]) return false;
	}
	
	for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
		if(board[i][j]) return false;
	}
	
	return true;
}

int backtracking(int col) {
	if(col == 8) return 1;
	
	int ans = 0;
	
	for(int i = 0; i < 8; i++) {
		if(isSafe(i, col)) {
			board[i][col] = 1;
			
			ans += backtracking(col + 1);
			
			board[i][col] = 0;
		}
	}
	
	return ans;
}

int main() {
	
	for(int i = 0; i < 8; i++) {
		cin >> vec[i];
	}
	
	memset(board, 0, sizeof(board));
	
	res = backtracking(0);
	
	cout << res << endl;
	
	return 0;
}
