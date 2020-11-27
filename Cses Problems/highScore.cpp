#include<bits/stdc++.h>
#define ll long long
#define ar array

using namespace std;

const int mxN = 2500;

int n, m;
ll score[mxN];
vector<ar<int, 2>> g[mxN];

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		int a, b, x;
		cin >> a >> b >> x, a--, b--;
		
		g[a].push_back({b, x});
	}
	
	for(int i = 0; i < n; i++) score[i] = -1e18;
	
	score[0] = 0;
	
	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(auto t: g[u]) {
				int v = t[0], x = t[1];
				if(score[u] + (ll)x > score[v]) {
					score[v] = score[u] + x;
				}
			}
		}
	}
	
	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(auto t: g[u]) {
				int v = t[0], x = t[1]; 
				if(score[u] + x > score[v]) {
					score[v] = 1e18;
				}
			}
		}
	}

	for(int i = 0; i < 100; i++) {
		cout << score[i] << " ";
	}
	cout << endl;

	if(score[n-1] >= 1e18) {
		cout << -1 << endl;
	} else {
		cout << score[n - 1] << endl;
	}
	
    return 0;
}

