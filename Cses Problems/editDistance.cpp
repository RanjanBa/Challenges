#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 5000;

string a, b;

int dp[mxN + 1][mxN + 1];

int overlap(int i, int j) {
	if(i <= 0) {
		return j;
	}
	
	if(j <= 0) {
		return i;
	}
	
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	
	int ans = 1e9;
	
	if(a[i - 1] == b[j - 1]) {
		ans = min(ans, overlap(i-1, j-1));
	} else {
		ans = min({overlap(i, j-1) + 1, overlap(i-1, j-1) + 1, overlap(i-1, j) + 1});
	}
	
	dp[i][j] = ans;
	
	return ans;
}

int solveByBacktracking() {
	int n = (int)a.size(), m = (int)b.size();
	
	if(m == 0) {
		return n;
	}
	
	if(n == 0) {
		return m;
	}
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
	return overlap(n, m);
}

int main() {
	cin >> a >> b;
	
	int n = (int)a.size(), m = (int)b.size();
	
	//for(int i = 0; i <= n; i++) {
		//dp[i][0] = i;
	//}
	
	//for(int i = 0; i <= m; i++) {
		//dp[0][i] = i;
	//}
	
	//for(int i = 1; i <= n; i++) {
		//for(int j = 1; j <= m; j++) {
			//if(a[i-1] == b[j-1]) {
				//dp[i][j] = dp[i-1][j-1];
			//} else {
				//dp[i][j] = min(dp[i - 1][j - 1], dp[i-1][j]);
				//dp[i][j] = min(dp[i][j], dp[i][j - 1]) + 1;
			//}
		//}
	//}

	//cout << dp[n][m] << endl;
	
	//for(int i = 0; i <= n; i++) {
		//for(int j = 0; j <= m; j++) {
			//cout << dp[i][j] << " ";
		//}
			
		//cout << "\n";
	//}
	
	cout << solveByBacktracking() << endl;
	
    return 0;
}

