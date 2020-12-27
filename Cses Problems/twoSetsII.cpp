#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 500, MOD = 1e9 + 7;

int n, a[mxN];

ll dp[mxN][mxN * (mxN + 1) / 2 + 1];
ll recursive(int index, int sum) {
	if(sum == 0) {
		return 1;
	}
	
	if(index >= n) {
		return 0;
	}
	
	if(dp[index][sum] != -1) {
		return dp[index][sum];
	}
	
	ll ans = 0;
	ans = (ans + recursive(index + 1, sum - a[index])) % MOD;
	ans = (ans + recursive(index + 1, sum)) % MOD;
	
	dp[index][sum] = ans;
	
	return ans;
}

//ll dp[mxN * (mxN + 1) / 2];
int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int sum = accumulate(a, a + n, 0);
	ll ans = 0;
	if(sum % 2 == 0) {
		sum /= 2;
		
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= sum; j++) {
				dp[i][j] = -1;
			}
		}
		
		ans = recursive(0, sum);
	}
	
	cout << ans * ((MOD + 1) / 2) % MOD << endl;
	
	
	//int sum = n * (n + 1) / 2;
	
	//if(sum&1) {
		//cout << 0 << endl;
		//return 0;
	//}
	
	//sum >>= 1;
	//dp[0] = 1;
	
	//for(int i = 1; i <= n; i++) {
		//for(int j = i* (i + 1) / 2; j >= i; j--) {
			//dp[j] = (dp[j] + dp[j - i]) % MOD;
		//}
	//}
	
	//cout << dp[sum] * ((MOD + 1) / 2) % MOD << endl;
	
    return 0;
}

