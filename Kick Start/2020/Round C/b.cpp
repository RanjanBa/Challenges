#include<bits/stdc++.h>

using namespace std;

int r, c;
set<int> grid[26];

int vis[26], visRes[26];

vector<int> res;
bool cycle = false;

void dfs(int idx) {
	vis[idx] = 1;
	
	for(int i : grid[idx]) {
		if(vis[i] == 0) {
			dfs(i);
		} else {
            if(visRes[i]==0) {
			    cycle = true;
			    return;
		    }
		}
	}
	
	visRes[idx] = 1;
	res.push_back(idx);
}

void solve() {
	cin >> r >> c;
	
	memset(vis, 0, sizeof(vis));
	memset(visRes, 0, sizeof(visRes));
	
	set<int> st;
	
	string prev;
	for(int i = 0; i < r; i++) {
		string str;
		cin >> str;

		for(char ch: str) st.insert(ch-'A');
		
		if(i) {
			for(int j = 0; j < c; j++) {
				int u = prev[j] - 'A', v = str[j] - 'A';
				if(u^v)
				    grid[u].insert(v);
			}
		}
		
		prev = str;
	}
	
	
	for(int i : st) {
		if(vis[i] == 0)
			dfs(i);
	}
	
	if(cycle) {
		cout << -1 << endl;
	} else {
		string str;
		for(int i : res) str += (char)('A' + i);
		
		cout << str << endl;
	}
	
	res.clear();
	cycle = false;
	for(int i = 0; i < 26; i++) grid[i].clear();
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

