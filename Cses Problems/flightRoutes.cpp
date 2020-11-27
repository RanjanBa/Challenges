#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5;

int n, m, k;
vector<ar<int, 2>> adj[mxN];
vector<ll> d[mxN];

int main() {
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		adj[a].phb({b, c});
	}
	
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	
	pq.push({0, 0});
	
	while(pq.size()) {
		ar<ll, 2> p = pq.top();
		pq.pop();
		ll cost = p[0];
		int u = p[1];
		if((int)d[u].size() >= k) continue;
		
		d[u].phb(cost);
		
		for(ar<int, 2> t : adj[u]) {
			int v = t[0], c = t[1];
			pq.push({cost + c, v});
		}
	}
	
	for(int i = 0; i < k; i++) {
		cout << d[n-1][i] << " ";
	}
	cout << endl;
    return 0;
}

