#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e5, mxM = 100, MOD = 1e9 + 7;

int n, m, a[mxN];
/*
//vector<int> v;
int recursive(int index, int cur, int prev) {
	if(cur > m) {
		return 0;
	}
	if(index > 0 && abs(prev - cur) > 1) {
		return 0;
	}
	
	if((a[index] != 0 && cur != a[index]) || cur == 0) {
		return 0;
	}
	
	//v.push(cur);
	
	if(index >= n - 1) {
		//for(int i: v) {
			//cout << i << " ";
		//}
		//cout << endl;
		//v.pop();
		return 1;
	}
	
	int ans = 0;
	
	if(a[index] == 0) {
		ans += recursive(index + 1, cur + 1, cur);
		ans += recursive(index + 1, cur, cur);
		ans += recursive(index + 1, cur - 1, cur);
	} else {
		ans += recursive(index + 1, a[index] + 1, cur);
		ans += recursive(index + 1, a[index], cur);
		ans += recursive(index + 1, a[index] - 1, cur);
	}
	
	//v.pop();
	
	return ans;
}
*/

int dp[mxN][mxM + 1];
int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	/*
	int ans = 0;
	if(a[0] == 0) {
		for(int i = 1; i <= m; i++) {
			//v.push(i);
			ans += recursive(1, i + 1, i);
			ans += recursive(1, i, i);
			ans += recursive(1, i - 1, i);
			//v.pop();
		}
	} else {
		//v.push(a[0]);
		if(n == 1) {
			ans = 1;
		} else {
			ans += recursive(1, a[0] + 1, a[0]);
			ans += recursive(1, a[0], a[0]);
			ans += recursive(1, a[0] - 1, a[0]);
		}
		//v.pop();
	}
	cout << ans << endl;
	*/
	
	for(int i = 0; i < n; i++) {
		if(i) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if(j) {
					dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
				}
				if(j < m) {
					dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
				}
			}
		}
		else {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = 1;
			}
		}
		
		if(a[i] != 0) {
			for(int j = 1; j <= m; j++) {
				if(j != a[i])
					dp[i][j] = 0;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=m; i++) {
		ans = (ans + dp[n-1][i]) % MOD;
	}
	
	cout << ans << endl;
	
	//for(int i = 0; i < n; i++) {
		//for(int j = 1; j <= m; j++) {
			//cout << dp[i][j] << " ";
		//}
		//cout << "\n";
	//}
	
    return 0;
}

/*
int dp[mxN][mxM];
int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i], --a[i];
	}
	
	for(int i = 0; i < n; i++) {
		if(i) {
			for(int j = 0; j < m; j++) {
				dp[i][j] = dp[i-1][j];
				
				if(j) {
					dp[i][j] += dp[i-1][j-1];
				}
				
				if(j < m - 1) {
					dp[i][j] += dp[i-1][j+1];
				}
			}
		} else {
			for(int j = 0; j < m; j++) {
				dp[i][j] = 1;
			}
		}
		
		if(~a[i])
			for(int j = 0; j < m; j++) {
				if(j^a[i])
					dp[i][j] = 0;
			}
	}
	
	int ans = 0;
	for(int j = 0; j < m; j++) {
		ans += dp[n-1][j];
	}
	
	cout << ans << "\n";
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}
*/
