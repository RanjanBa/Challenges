//Floyd Warshell algorithm

#include<bits/stdc++.h>
#define ll long long
#define ar array
 
using namespace std;
 
const int mxN = 500, mxM = 2e5;
 
int n, m, q;
ll dp[mxN][mxN];
 
int main() {
	cin >> n >> m >> q;
	memset(dp, 0x3f, sizeof(dp));
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		dp[a][b] = min(dp[a][b], (ll)c);
		dp[b][a] = min(dp[b][a], (ll)c);
	}
	
	for(int i = 0; i < n; i ++) dp[i][i] = 0;
	
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	while(q--) {
		int a, b;
		cin >> a >> b, a--, b--;
		if(dp[a][b] >= 1e18) {
			cout << -1 << endl;
		} else {
			cout << dp[a][b] << endl;
		}
	}
	
    return 0;
}
