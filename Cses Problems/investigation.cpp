#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5, MOD = 1e9 + 7;

int n, m, vis[mxN];
ll dst[4][mxN];
vector<ar<ll, 2>> adj[mxN];

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		adj[a].phb({b, c});
	}
	
	for(int i = 0; i < n; i++) {
		dst[0][i] = 1e18, dst[1][i] = 0, dst[2][i] = 0, dst[3][i] = 0;
	}
	
	memset(vis, 0, sizeof(vis));
	
	priority_queue<ar<ll, 5>, vector<ar<ll,5>>, greater<ar<ll, 5>>> pq;
	
	pq.push({0, 0});
	dst[1][0] = 1;
	while(pq.size()) {
		ar<ll,5> p = pq.top();
		pq.pop();
		
		ll d = p[0], u = p[4];
		
		vis[u] = 1;
		
		for(ar<ll, 2> t: adj[u]) {
			ll v = t[0], c = t[1];
			if(c + d < dst[0][v]) {
				dst[0][v] = c + d;
				dst[1][v] = dst[1][u];
				dst[2][v] = dst[2][u] + 1;
				dst[3][v] = dst[3][u] + 1;
				pq.push({dst[0][v], dst[1][v], dst[2][v], dst[3][v], v});
			} else if(c + d == dst[0][v]) {
				dst[1][v] = (dst[1][v] + dst[1][u]) % MOD;
				dst[2][v] = min(dst[2][v], dst[2][u] + 1);
				dst[3][v] = max(dst[3][v], dst[3][u] + 1);
			}
		}
	}
	
	cout << dst[0][n-1] << " " << dst[1][n-1] << " " << dst[2][n-1] << " " << dst[3][n-1] << endl;

	//cout << ans[0] << " " << ans[1] << " " << ans[2] - 1 << " " << ans[3] - 1 << endl;
	
    return 0;
}

