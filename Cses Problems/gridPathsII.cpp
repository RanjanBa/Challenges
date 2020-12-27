#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1000, MOD = 1e9 + 7;

int n, g[mxN][mxN], dp[mxN][mxN];

int recusive(ar<int, 2> p) {
	if(p[0] >= n || p[1] >= n) {
		return 0;
	}
	
	if(dp[p[0]][p[1]] != -1) {
		return dp[p[0]][p[1]];
	}
	
	if(g[p[0]][p[1]] == 0) {
		return 0;
	}
	
	if(p[0] == n - 1 && p[1] == n - 1) {
		return 1;
	}
	
	int  ans = recusive({p[0] + 1, p[1]});
	ans = (ans + recusive({p[0], p[1] + 1})) % MOD;
	
	dp[p[0]][p[1]] = ans;
	
	return ans;
}

int main() {	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		for(int j = 0; j < n; j++) {
			if(s[j] == '.') {
				g[i][j] = 1;
			} else {
				g[i][j] = 0;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << recusive({0, 0}) << endl;
	
    return 0;
}

