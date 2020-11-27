#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5;

int n, m, p[mxN], dp[mxN];
vector<int> adj[mxN];

int dfs(int u) {
	if(u == n - 1) {
		return 1;
	}
	
	if(dp[u] != -1) {
		return dp[u] == 0 ? 0 : dp[u] + 1;
	}
	
	int d = 0;
	for(int v: adj[u]) {
		int t = dfs(v);
		if(t >= d) {
			p[u] = v;
			d = t;
		}
	}
	
	dp[u] = d;
	//cout << "u: " << u << ",d: " << d << endl;
	return d == 0 ? 0 : d + 1;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].phb(b);
	}
	
	memset(p, -1, sizeof(p));
	memset(dp, -1, sizeof(dp));
	int s = dfs(0);
	
	if(s == 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	//cout << "path: ";
	//for(int i = 0; i < n; i++) {
		//cout << p[i] + 1 << " ";
	//}
	//cout << endl;
	
	vector<int> ans;
	int u = 0;
	while(u != n - 1) {
		ans.phb(u);
		u = p[u];
	}
	ans.phb(u);

	//cout << "size: " << ans.size() << endl;
	
	cout << s << endl;
	for(int i: ans) {
		cout << i + 1 << " ";
	}
	
	cout << endl;
	
    return 0;
}

