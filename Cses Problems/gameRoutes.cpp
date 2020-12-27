#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5, MOD = 1e9 + 7;

int n, m, dp[mxN];
vector<int> adj[mxN];

int dfs(int u) {
	if(u == n-1)
		return 1;
	
	if(dp[u] != -1) return dp[u];
	
	int d = 0;
	for(int v: adj[u]) {
		d += dfs(v);
		d %= MOD;
	}
	dp[u] = d % MOD;
	return dp[u];
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		adj[a].phb(b);
	}
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0);
	
	cout << ans << endl;
	
    return 0;
}

