#include<bits/stdc++.h>

using namespace std;

const int mxN = 1000;

int mat[mxN][mxN];

void solve() {
	int n;
	
	cin >> n;

	int diagonal = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if(i == j) diagonal += mat[i][j];
		}
	}

	int r = 0;
	int dp[n+1];
	for(int i = 0; i < n; i++) {
		memset(dp, 0, sizeof(dp));
		for(int j = 0; j < n; j++) {
			int d = mat[i][j];
			if(dp[d] == 1) {
				r++;
				break;
			}
			dp[d] = 1;
		}
	}

	int c = 0;
	for(int i = 0; i < n; i++) {
		memset(dp, 0, sizeof(dp));
		for(int j = 0; j < n; j++) {
			int d = mat[j][i];
			if(dp[d] == 1) {
				c++;
				break;
			}
			dp[d] = 1;
		}
	}
	
	cout << diagonal << " " << r << " " << c << endl;
}

int main() {
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}
