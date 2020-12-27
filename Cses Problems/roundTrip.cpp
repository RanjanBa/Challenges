#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e5, mxM = 2e5;

int n, m, path[mxN];
vector<int> g[mxN];
bool visited[mxN];

void dfs(int v, int parent = -1) {
	visited[v] = true;
	path[v] = parent;
	for(int i: g[v]) {
		if(i == parent)
			continue;
		if(!visited[i]) {
			dfs(i, v);
		} else {
			int c = v;
			vector<int> ans;
			while(c != i) {
				ans.push(c + 1);
				c = path[c];
			}
			ans.push(c + 1);
			ans.push(v + 1);
			
			cout << ans.size() << endl;
			for(int j : ans) {
				cout << j << " ";
			}
			cout << endl;
			exit(0);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push(b);
		g[b].push(a);
	}
	
	for(int i = 0; i < n; i++) {
		if(!visited[i])
			dfs(i, -1);
	}
	
	cout << "IMPOSSIBLE" << endl;
	
    return 0;
}

