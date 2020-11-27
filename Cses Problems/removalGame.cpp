#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 5000;

int n, x[mxN];

ll dp[mxN][mxN];

ll recursive(int s, int e, ll sum) {
	if(e == s) {
		return x[s];
	}
	if(e == s + 1) {
		return max(x[s], x[e]);
	}
	
	if(dp[s][e] != LLONG_MIN)
		return dp[s][e];
	
	ll ans = -1e18;
 	ans = max(ans, sum - recursive(s + 1, e, sum - x[s]));
	ans = max(ans, sum - recursive(s, e - 1, sum - x[e]));
	
	dp[s][e] = ans;
	
	return ans;
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	ll sum = 0;
	
	sum = accumulate(x, x + n, sum);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = LLONG_MIN;
		}
	}
	
	cout << recursive(0, n - 1, sum) << endl;
	
    return 0;
}

