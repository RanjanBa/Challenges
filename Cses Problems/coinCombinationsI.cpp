#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 100, mxX = 1e6, MOD = 1e9 + 7;

int n, x, c[mxN];

//int overlapping(int remSum) {
	//if(remSum < 0) {
		//return 0;
	//}
	
	//if(remSum == 0) {
		//return 1;
	//}
	
	//int ans = 0;
	//for(int i = 0; i < n; i++) {
		//ans = (ans + overlapping(remSum - c[i])) % MOD;
	//}
	
	//return ans;
//}

//map<ar<int, 2>, int> dp;
//int memoization(int remSum, int numCoins = 0) {
	//cout << "rem: " << remSum << ",";
	//if(remSum < 0) {
		//return 0;
	//}
	
	//if(remSum == 0) {
		//return 1;
	//}
	
	//if(dp.find({remSum, numCoins}) != dp.end()) {
		//return dp[{remSum, numCoins}];
	//}
	
	//int ans = 0;
	//for(int i = 0; i < n; i++) {
		//ans += memoization(remSum - c[i], numCoins + 1);
		//ans %= MOD;
	//}
	
	//dp[{remSum, numCoins}] = ans;
	
	//return ans;
//}

int dp[mxX + 1];
int memoization(int rem) {
	if(rem < 0) {
		return 0;
	}
	
	if(rem == 0) {
		return 1;
	}
	
	if(dp[rem] != -1) {
		return dp[rem];
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans + memoization(rem - c[i])) % MOD;
	}
	
	dp[rem] = ans;
	
	return ans;
}

int memoizationBU() {
	dp[0] = 1;
	for(int i = 1; i <= x; i++) {
		dp[i] = 0;
		for(int j = 0; j < n; j++) {
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
	
	for(int i = 0; i <= x; i++) {
		dp[i] = -1;
	}
	
	//cout << overlapping(x) << endl;
	//cout << memoization(x) << endl;
	cout << memoizationBU() << endl;
	
	//for(int i = 1; i <= x; i++) {
		//cout << dp[i] << " ";
	//}
	//cout << endl;
    return 0;
}

