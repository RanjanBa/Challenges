#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5;

int n, m, vis[mxN];
set<int> st;
vector<int> adj[mxN], ans;

void dfs(int u) {
	vis[u] = 1;
	if(st.find(u) != st.end())
		return;
	for(int v: adj[u]) {
		if(vis[v] == 0) {
			dfs(v);
		} else {
			if(st.find(v) == st.end()) {
				cout << "IMPOSSIBLE" << endl;
				exit(0);
			}
		}
	}
	
	st.insert(u);
	ans.phb(u);
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].phb(b);
	}
	
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < n; i++) {
		dfs(i);
	}
	
	for(int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
    return 0;
}

