#include<bits/stdc++.h>
#define ll long long
#define ar array
#define phb push_back
#define ppb pop_back
using namespace std;

const int mxN = 1e5;

int n, e[mxN], r[mxN];

ll ans = 0, removedToys = 1e18;

void check(vector<int>& toys) {
	if(toys.size() == 0) return;
	
	ll total = 0;
	for(int i = 0; i < (int)toys.size(); i++) {
		int index = toys[i];
		total += e[index];
	}
	
	ll t = total;
	
	for(int i = 0 ; i < (int)toys.size(); i++) {
		int index = toys[i];
		if(t < r[index] + e[index]) {
			if(ans < total) {
				ans = total;
				removedToys = n - toys.size();
			} else if(ans == total) {
				removedToys = min(removedToys,(ll)(n-toys.size()));
			}
			return;
		}
		
		total += e[index];
	}
	
	if(ans == 1e18) {
		removedToys = min(removedToys, (ll)(n - toys.size()));
	} else {
		ans = 1e18;
		removedToys = n - toys.size();
	}
}

void dfs(int index, vector<int>& toys) {
	if(index == n) {
		check(toys);
		return;
	}
	
	toys.phb(index);
	dfs(index + 1, toys);
	toys.ppb();
	
	dfs(index + 1, toys);
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> e[i] >> r[i];
	}
	
	vector<int> toys;
	ans = 0, removedToys = 0;
	dfs(0, toys);
	if(ans == 1e18) {
		cout << removedToys  << " INDEFINITELY" << endl;
	} else {
		cout << removedToys << " " << ans << endl;
	}
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
