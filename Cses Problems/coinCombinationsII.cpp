#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 100, mxX = 1e6, MOD = 1e9 + 7;

int n, x, c[mxN];

/*
int overlapping(int rem, int end) {
	if(rem < 0 || end < 0) {
		return 0;
	}
	
	if(rem == 0) {
		return 1;
	}
	
	int ans = 0;
	for(int i = end; i >= 0; i--) {
		if(rem < c[i]) {
			ans = (ans + overlapping(rem, end - 1)) % MOD;
			break;
		}
		
		if(rem >= c[i]) {
			ans = (ans + overlapping(rem - c[i], i)) % MOD;
		}
	}

	return ans;
}
*/

/*
int dp[mxX + 1][mxN];
int memoization(int rem, int end) {
	cout << rem << endl;
	if(rem < 0 || end < 0) {
		cout << "rem end" << endl;
		return 0;
	}
	
	if(rem == 0) {
		cout << "rem" << endl;
		return 1;
	}
	
	if(dp[rem][end] != -1) {
		return dp[rem][end];
	}
	
	int ans = 0;
	for(int i = end; i >= 0; i--) {
		if(rem < c[i]) {
			int t = memoization(rem, end - 1);
			ans = (ans + t) % MOD;
			break;
		}
		
		if(rem >= c[i]) {
			int t = memoization(rem - c[i], i);
			ans = (ans + t) % MOD;
		}
	}
	
	dp[rem][end] = ans;
	
	return ans;
}
*/

/*
int dp[mxX + 1];
int memoization(int rem, int end) {
	if(rem < 0 || end < 0) {
		return 0;
	}
	
	if(rem == 0) {
		return 1;
	}
	
	if(dp[rem][end] != -1) {
		return dp[rem][end];
	}
	
	int ans = 0;
	for(int i = end; i >= 0; i--) {
		if(rem < c[i]) {
			int t = memoization(rem, end - 1);
			ans = (ans + t) % MOD;
			break;
		}
		
		if(rem >= c[i]) {
			int t = memoization(rem - c[i], i);
			ans = (ans + t) % MOD;
		}
	}
	
	dp[rem] = ans;
	
	return ans;
}
*/

int dp[mxX + 1];
int memoizationBU() {
	dp[0] = 1;
	
	for(int j = 0; j < n; j++) {
		for(int i = 1; i <= x; i++) {
			if(i >= c[j]) {
				dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
			}
		}
	}
	
	return dp[x];
}

int main() {
	cin >> n >> x;
	
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	/*
	sort(c, c + n);
	for(int i = 0; i <= x; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << overlapping(x, n - 1) << endl;
	cout << memoization(x, n - 1) << endl;
	*/
	
	cout << memoizationBU() << endl;
    return 0;
}

