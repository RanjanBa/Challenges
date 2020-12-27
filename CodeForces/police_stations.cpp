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

const int mxN = 3e5+10;

vector<int> gp[mxN];
int vis[mxN];
map<pair<int, int>, int> edges;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	int n, k, d;
	cin >> n >> k >> d;
	
	queue<arr<int, 3>> qu;
	
	memset(vis, 0, sizeof(vis));
	
	FOR(i, k) {
		int p;
		cin >> p;
		qu.push({p, -1, 0});
		//vis[p] = 1;
	}
	
	FORS(i, 1, n) {
		int u, v;
		cin >> u >> v;
		edges[{u, v}] = i;
		edges[{v, u}] = i;
		
		gp[u].phb(v);
		gp[v].phb(u);
	}
	
	vector<int> res;
	
	while(qu.size()) {
		arr<int, 3> tp = qu.front();
		qu.pop();
		int u = tp[0];
		
		if(vis[u]) continue;
		
		vis[u] = 1;
		
		FORV(v, gp[u]) {
			if(v == tp[1]) continue;
			
			if(vis[v]) {
				if(edges.find({u, v}) != edges.end()) {
					res.phb(edges[{u, v}]);
					//cout << "u: " << u << ", v: " << v << ",,," << edges[{u, v}] << ", " << edges[{v, u}] << endl;
					edges.erase({u, v});
					edges.erase({v, u});
				}
			} else if(tp[2] < d){
				qu.push({v, u, tp[2] + 1});
				//vis[v] = 1;
			}
		}
	}
	
	
	cout << res.size() << endl;
	
	if(res.size()) {
		sort(res.begin(), res.end());
		
		FORV(v, res) {
			cout << v << " ";
		}
		cout << endl;
	}
	
	return 0;
}
