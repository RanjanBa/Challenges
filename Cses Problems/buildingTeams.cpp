#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e5, mxM = 2e5;

int n, m, col[mxN];
vector<int> g[mxN];
bool visited[mxN];

void dfs(int i) {
	visited[i] = true;
	for(int j: g[i]) {
		if(!visited[j]) {
			col[j] = col[i] ^ 1;
			dfs(j);
		} else {
			if(col[i] == col[j]) {
				cout << "IMPOSSIBLE" << endl;
				exit(0);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		g[u].push(v);
		g[v].push(u);
	}
	
	memset(col, -1, 4 * n);
	
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			col[i] = 0;
			dfs(i);
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << col[i] + 1 << " ";
	}
	cout << endl;
    return 0;
}

