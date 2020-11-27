#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e5, mxM = 2e5;

int n, m;
vector<int> g[mxN + 1];
bool vis[mxN + 1];

void dfs(int i) {
	vis[i] = true;
	for(int j = 0; j < (int)g[i].size(); j++) {
		if(!vis[g[i][j]]) {
			dfs(g[i][j]);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		g[a].push(b);
		g[b].push(a);
	}
	
	int k = 0;
	
	vector<int> ans;
	
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i);
			ans.push(i);
			k++;
		}
	}
	
	cout << k - 1 << endl;
	
	for(int i = 1; i < ans.size(); i++) {
		cout << ans[i - 1] << " " << ans[i] << endl;
	}
	
    return 0;
}

