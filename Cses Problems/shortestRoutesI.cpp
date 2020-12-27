#include<bits/stdc++.h>
#define ll long long
//#define push push_back
//#define pop pop_back
#define ar array
 
using namespace std;
 
const int mxN = 1e5, mxM = 2e5;
 
int n, m, vis[mxN];
vector<ar<int, 2>> g[mxN];
ll dis[mxN];
 
void bfs() {
	memset(vis, 0, sizeof(vis));
 
	for(int i = 0; i < n; i++) dis[i] = 1e18;
	
	priority_queue<ar<ll, 2>> pq;
	pq.push({0, 0});
	
	dis[0] = 0;
	
	while(!pq.empty()) {
		ar<ll, 2> fr = pq.top();
		pq.pop();
		
		ll d = (-1) * fr[0];
		int u = fr[1];
		
		vis[u] = 1;
		for(ar<int, 2> p: g[u]) {
			int v = p[0], c = p[1];
			if(vis[v]) continue;
			
			ll newCost = d + c;
			
			if(newCost < dis[v]) {
				dis[v] = newCost;
				pq.push({(-1) * newCost, v});
			}			
		}
	}
}
 
int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		g[a].push_back({b, c});
	}
	
	bfs();
	
	for(int i = 0; i < n; i++) {
		cout << dis[i] << " ";
	}
	
	cout << endl;
	
    return 0;
}
