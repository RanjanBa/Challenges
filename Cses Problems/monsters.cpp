#include<bits/stdc++.h>
#define ll long long
//#define push push_back
//#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1000, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};

int n, m;
string g[mxN];
int d1[mxN][mxN], d2[mxN][mxN], p[mxN][mxN], vis[mxN][mxN];

bool e(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && g[i][j] == '.' && vis[i][j] == 0;
}

void bfs(vector<ar<int, 2>> v, int d[mxN][mxN]) {
	//memset(d, -1, sizeof(d1));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			d[i][j] = 1e9;
		}
	}
	memset(p, -1, sizeof(p));
	memset(vis, 0, sizeof(vis));
	
	queue<ar<int, 2>> qu;
	for(auto t: v) {
		qu.push(t);
		vis[t[0]][t[1]] = 1;
		d[t[0]][t[1]] = 0;
	}
	
	while(qu.size()) {
		ar<int, 2> pa = qu.front();
		qu.pop();
		int i = pa[0], j = pa[1];
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];
			if(e(ni, nj)) {
				qu.push({ni, nj});
				vis[ni][nj] = 1;
				d[ni][nj] = d[i][j] + 1;
				p[ni][nj] = k;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	vector<ar<int,2>> mons;
	int si = 0, sj = 0;
	
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		g[i] = s;
		
		for(int j = 0; j < m; j++) {
			if(g[i][j] == 'A') {
				si = i, sj = j, g[i][j] = '.';
			} else if(g[i][j] == 'M') {
				mons.push_back({i, j}), g[i][j] = '.';
			}
		}
	}
	
	bfs(mons, d2);
	bfs({{si, sj}}, d1);
	
	int ti = -1, tj = -1;
	
	for(int i = 0; i < n; i++) {
		if(d1[i][0] < d2[i][0]) {
			ti = i, tj = 0;
		}
		
		if(d1[i][m-1] < d2[i][m-1]) {
			ti = i, tj = m - 1;
		}
	}
	
	for(int j = 0; j < m; j++) {
		if(d1[0][j] < d2[0][j]) {
			ti = 0, tj = j;
		}
		
		if(d1[n - 1][j] < d2[n - 1][j]) {
			ti = n - 1, tj = j;
		}
	}
	
	if(~ti) {
		string t;
		while(si ^ ti || sj ^ tj) {
			t += dc[p[ti][tj]];
			
			int dd = p[ti][tj] ^ 2;
			ti += di[dd];
			tj += dj[dd];
		}
		reverse(t.begin(), t.end());
		cout << "YES\n" << t.size() << endl;
		if(t.size())
			cout << t << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	
    return 0;
}

