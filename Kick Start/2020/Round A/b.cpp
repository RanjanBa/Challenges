#include<bits/stdc++.h>

using namespace std;

#define arr array

int plates[50][31];

int n, k, p;

map<arr<int, 2>, int> mp;

int dfs(int beauty, int i, int tot) {
	if(tot == p) {
		return beauty;
	}
	
	if(i >= n || tot > p) return 0;
	
	if(mp.count({i, tot})) return mp[{i, tot}] + beauty;
	
	int ans = 0;
	int b = 0;
	for(int c = 0; c <= k && tot + c <= p; c++) {
		b += plates[i][c];
		ans = max(ans, dfs(beauty + b, i + 1, tot + c));
	}
	mp[{i, tot}] = ans - beauty;
	return ans;
}

void solve() {
    cin >> n >> k >> p;
    
    //plates.resize(n, vector<int>(k+1, 0));

    for(int i = 0; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			cin >> plates[i][j];
		}
	}
	
	int ans = dfs(0, 0, 0);
    
    cout << ans << endl;
    mp.clear();
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
