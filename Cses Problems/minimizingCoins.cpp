#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxX = 1e6;

int n, x, c[100];
int dp[mxX + 1];

//int overlaping(int s = 0, int numCoins = 0) {
	//if(s > x) {
		//return INT_MAX;
	//} else if(s == x) {
		//return numCoins;
	//}
	
	//int ans = INT_MAX;
	//for(int i = 0; i < n; i++) {
		//ans = min(ans, overlaping(s + c[i], numCoins + 1));
	//}
	
	//return ans;
//}


// bottom up approach
int memoization() {
	for(int i = 1; i <= x; i++) {
		dp[i] = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(i >= c[j] && dp[i-c[j]] < INT_MAX) {
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}
	}
	
	return dp[x];
}

// top down approach
//int memoization(int s = 0, int numCoins = 0) {
	//if(dp[s] != INT_MAX) {
		//return numCoins + dp[s];
	//}
	
	//if(s == x) {
		//return numCoins;
	//}
	
	//int ans = INT_MAX;
	
	//for(int i = 0; i < n; i++) {
		//if(s + c[i] > x) {
			//continue;
		//}
		
		//int t = memoization(s + c[i], numCoins + 1);
		//ans = min(ans, t);
	//}
	
	//if(ans != INT_MAX) {
		//dp[s] = ans - numCoins;
	//}
	
	//return ans;
//}

int main() {
	cin >> n >> x;
	
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	//for(int i = 0; i <= x; i++) {
		//dp[i] = INT_MAX;
	//}
	
	int ans = memoization();
	
	if(ans != INT_MAX) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
	
    return 0;
}

