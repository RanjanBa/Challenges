//TODO::

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
#define FORS(i, s, x) for(int i = s; i < x; i++)
#define FORR(i, x) for(int i = x - 1; i >= 0; i--)
#define FORV(v, li) for(auto v : li)

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
	FORV(v, li) {
		cout << v << " ";
	}
	
	cout << endl;
}

template<typename T>
inline void debug(vector<vector<T>> li) {
	FORV(v1, li) {
		FORV(v2, v1) {
			cout << v2 << " ";
		}
		
		cout << endl;
	}
}

// ------ main function ------

const int mxN = 3e3+5, INF = 1e9;

vector<int> gp[mxN];
set<vector<int>> trip;
int n, m, k,vis[mxN][mxN], dist[mxN][mxN];
pair<int, int> pa[mxN][mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	
	FOR(i, m) {
		int u, v;
		cin >> u >> v;
		
		gp[u].phb(v);
		gp[v].phb(u);
	}
	
	FOR(i, k) {
		int a, b, c;
		cin >> a >> b >> c;
		
		trip.insert({a, b, c});
	}
	
	memset(pa, -1, sizeof(pa));
	memset(vis, 0, sizeof(mxN));
	FOR(i, n+1) {
		FOR(j, n + 1) {
			dist[i][j] = INF;
		}
	}
	
	queue<arr<int, 3>> qu;
	qu.push({1, 0, 0});
	
	dist[1][0] = 0;
	pa[1][0] = {-1, -1};
	vis[1][0] = 1;
	
	while(qu.size()) {
		arr<int,3> tp = qu.front();
		int u = tp[0];
		qu.pop();
		
		FORV(v, gp[u]) {
			if(vis[v][u]) continue;
			
			if(trip.find({tp[2], u, v}) == trip.end()) {
				pa[v][u] = {u, tp[2]};
				vis[v][u] = 1;
				dist[v][u] = min(dist[v][u], tp[1] + 1);
				qu.push({v, dist[v][u], u});
			}
		}
	}
	
	int prev = -1;
	
	int mi = INF;
	
	FOR(i, n) {
		if(dist[n][i] < mi) {
			prev = i;
			mi = dist[n][i];
		}
	}
	
	if(prev != -1) {
		vector<int> path;
		path.phb(n);
		
		int cur = n;
		while(prev > 0) {
			path.phb(prev);
			prev = pa[cur][prev].second;
			cur = prev;
		}
		
		reverse(path.begin(), path.end());
		
		cout << (path.size() - 1) << endl;
		
		FORV(v, path) {
			cout << v << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	
	return 0;
}
