#include<bits/stdc++.h>
#define arr array

using namespace std;

const int mxN = 250, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int r, c, p[mxN][mxN], vis[mxN][mxN];
int ans;

bool e(int i, int j) {
	return i >= 0 && i < r && j >= 0 && j < c && !vis[i][j];
}

void check(arr<int, 2> v) {
	memset(vis, 0, sizeof(vis));
	int dp[r][c];
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			dp[i][j] = p[i][j];
		}
	}
	
	queue<arr<int, 3>> qu;
	qu.push({v[0], v[1], 0});
	
	dp[v[0]][v[1]] = 0;
	vis[v[0]][v[1]] = 1;
	
	while(!qu.empty()) {
		arr<int, 3> a = qu.front();
		qu.pop();
		int i = a[0], j = a[1], d = a[2];
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];
			if(e(ni, nj)) {
				vis[ni][nj] = 1;
				dp[ni][nj] = min(dp[ni][nj], d + 1);
				qu.push({ni, nj, d + 1});
			}
		}
	}
	
	int mx = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			mx = max(mx, dp[i][j]);
		}
	}
	
	ans = min(ans, mx);
}

void bfs(arr<int, 2> v) {
	memset(vis, 0, sizeof(vis));
	
	queue<arr<int, 3>> qu;
	qu.push({v[0], v[1], 0});
	
	p[v[0]][v[1]] = 0;
	vis[v[0]][v[1]] = 1;
	
	while(!qu.empty()) {
		arr<int, 3> a = qu.front();
		qu.pop();
		int i = a[0], j = a[1], d = a[2];
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];
			if(e(ni, nj)) {
				vis[ni][nj] = 1;
				p[ni][nj] = min(p[ni][nj], d + 1);
				qu.push({ni, nj, d + 1});
			}
		}
	}
}

void solve() {
	cin >> r >> c;
	
	vector<string> b(r);
	
	vector<arr<int, 2>> off;
	
	for(int i = 0; i < r; i++) {
		cin >> b[i];
		
		for(int j = 0; j < c; j++) {
			if(b[i][j] == '1') {
				off.push_back({i, j});
			}
		}
	}
	
	ans = INT_MAX;
	memset(p, 0x3f3f, sizeof(p));
	
	for(int i = 0; i < (int)off.size(); i++) {
		bfs(off[i]);
	}
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			check({i, j});
		}
	}
	
	cout << ans << endl;
	
	//cout << endl;
	//for(int i = 0; i < r; i++) {
		//for(int j = 0; j < c; j++) {
			//cout << p[i][j] << " ";
		//}
		//cout << endl;
	//}
}

int main() {
	int t;
	
	cin >> t;
	
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
}
