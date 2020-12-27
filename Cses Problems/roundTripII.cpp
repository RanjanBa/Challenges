#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5;

int n, m, vis[mxN], act[mxN], path[mxN];
vector<int> adj[mxN];

void dfs(int u, int p = -1) {
	vis[u] = 1;
	path[u] = p;
	act[u] = 1;
	
	for(int v: adj[u]) {
		if(act[v]) {
			vector<int> ans;
			ans.phb(v);
			int t = u;
			while(t^v) {
				ans.phb(t);
				t = path[t];
			}
			
			ans.phb(v);
			reverse(ans.begin(), ans.end());
			cout << ans.size() << endl;
			for(int i : ans) {
				cout << i + 1 << " ";
			}
			cout << endl;
			exit(0);
		} else {
			if(vis[v] == 0)
				dfs(v, u);
		}
	}
	
	act[u] = 0;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b, --a, --b;
		
		adj[a].phb(b);
	}
	
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < n; i++) {
		if(vis[i] == 0) dfs(i, -1);
	}
	
	cout << "IMPOSSIBLE" << endl;
	
    return 0;
}

