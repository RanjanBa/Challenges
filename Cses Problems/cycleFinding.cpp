#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2500, mxM = 5000;

int n, m, path[mxN];
ll dist[mxN];
vector<ar<int, 2>> g[mxN];

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].phb({b, c});
	}
	
	memset(dist, 0x3f, sizeof(dist));
	memset(path, -1, sizeof(path));
	
	dist[0] = 0;
	int x = -1;
	for(int i = 0; i < n; i++) {
		x = -1;
		for(int u = 0; u < n; u++) {
			for(ar<int, 2> a: g[u]) {
				int v = a[0], c = a[1];
				if(dist[u] + c < dist[v]) {
					dist[v] = dist[u] + c;
					path[v] = u;
					x = v;
				}
			}
		}
	}
	
	if(x == -1) {
		cout << "NO" << endl;
	} else {
		for (int i = 0; i < n; ++i)
			x = path[x];
			
		cout << "YES" << endl;
		
		vector<int> ans;
		ans.phb(x);
		
		int v = path[x];
		
		//int j = 0;
		while(v != x) {
			//cout << "v: " << v << endl;
			ans.phb(v);
			v = path[v];
		}
		
		ans.phb(x);
		
		reverse(ans.begin(), ans.end());
		
		for(int i = 0; i < (int)ans.size(); i++)
			cout << ans[i] + 1 << " ";
		
		cout << endl;
	}
	
    return 0;
}

