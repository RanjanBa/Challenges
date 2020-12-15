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

const int mxN = 5e4;

arr<int, 2> vec[mxN];

int n, m;

bool dfs(int idx, int rem, vector<int>& p, set<int>& vis, set<int>& row, set<int>& col) {
	if(rem == 0) {		
		return true;
	}
	
	int r = vec[idx][0], c = vec[idx][1];
	
	FOR(i, m) {
		if(vis.size() == 0 || vis.find(i) == vis.end()) {
			int nr = vec[i][0], nc = vec[i][1];
			
			if((row.size() == 0 || row.find(nr) == row.end()) && r == nr) {
				row.insert(nr);
				p.phb(i);
				vis.insert(i);
				
				bool res = dfs(i, rem - 1, p, vis, row, col);
				if(res) return true;
				
				p.ppb();
				row.erase(nr);
				vis.erase(i);
			}
			
			if((col.size() == 0 || col.find(nc) ==  col.end()) && c == nc) {
				col.insert(nc);
				p.phb(i);
				vis.insert(i);
				
				bool res = dfs(i, rem - 1, p, vis, row, col);
				if(res) return true;
				
				p.ppb();
				col.erase(nc);
				vis.erase(i);
			}
		}
	}
	
	return false;
}

void solve() {
	cin >> n >> m;
	
	FOR(i, m) {
		cin >> vec[i][0] >> vec[i][1];
	}
	
	vector<int> p;
	set<int> vis, row, col;

	bool res = false;
	
	FOR(i, m) {
		vis.insert(i);
		p.phb(i);
		res = dfs(i, m - 1, p, vis, row, col);
		if(res) break;
		p.ppb();
		vis.erase(i);
	}
	
	FORV(v, p) {
		cout << (v + 1) << " ";
	}
	
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        //cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

