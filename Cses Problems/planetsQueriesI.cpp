#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q;

//vector<int> adj[mxN];
//int dfs(int s, int k, map<int, int> mp) {	
	//if(mp.find(s) != mp.end()) {
		//int cn = mp[s] - k;
		//k = k % cn;
		//map<int, int> m;
		//mp = m;
	//}
	
	//if(k == 0) {
		//return s;
	//}
	
	//mp[s] = k;
	
	//return dfs(adj[s][0], --k, mp);
//}

// Binary Lifting
int biLift[30][mxN];

int main() {
	cin >> n >> q;
	
	for(int i = 0; i < n; i++) {
		//int v;
		//cin >> v, v--;
		//adj[i].push_back(v);
		cin >> biLift[0][i], biLift[0][i]--;
	}
	
	for(int j = 1; j < 30; j++) {
		for(int i = 0; i < n; i++) {
			biLift[j][i] = biLift[j-1][biLift[j-1][i]];
		}
	}
	
	while(q--) {
		int s, k;
		cin >> s >> k, --s;
		//map<int, int> st;
		//cout << dfs(s, k, st) + 1 << endl;
		
		for(int i = 0; i < 30; i++) {
			if(k >> i & 1) {
				s = biLift[i][s];
			}
		}
		
		cout << s + 1 << endl;
	}
	
    return 0;
}

