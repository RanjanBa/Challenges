#include<bits/stdc++.h>
#define ll long long
//#define pun push_back
//#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e5, mxM = 2e5;

int n, m, vi[mxN], p[mxN];

vector<int> g[mxN];

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++) {
		p[i] = -1;
	}
	
	int s = 0, e = n - 1;
	
	queue<int> qu;
	qu.push(s);
	vi[s] = true;
	while(qu.size()) {
		int i = qu.front();
		qu.pop();
		
		for(int j = 0; j < g[i].size(); j++) {
			int t = g[i][j];
			if(!vi[t]) {
				qu.push(t);
				vi[t] = true;
				p[t] = i;
			}
		}
	}
	
	if(p[e] == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	
	vector<int> ans;
	ans.push_back(n);
	while(p[e] != -1) {
		ans.push_back(p[e] + 1);
		e = p[e];
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(int i : ans) {
		cout << i << " ";
	}
	cout << endl;
    return 0;
}

