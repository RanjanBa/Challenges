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
#define SZ(v) (int)v.size()
#define all(v) v.begin() , v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li,v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
	FORV(v, li) {
		cout << v << " ";
	}
	
	cout << "\n";
}

template<typename T>
inline void debug(vector<vector<T>> li) {
	FORV(v1, li) {
		FORV(v2, v1) {
			cout << v2 << " ";
		}
		
		cout << "\n";
	}
}

const int mxN = 2000;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int vec[mxN][mxN];

int mirow[10], mxrow[10], micol[10], mxcol[10];

void solve() {
	int n;
	cin >> n;
	
	FOR(i, n) {
		string str;
		cin >> str;
		
		FOR(j, n) {
			vec[i][j] = (int)(str[j] - '0');
		}
	}
	
	FOR(i, 10) {
		mirow[i] = INF;
		mxrow[i] = -1;
		micol[i] = INF;
		mxcol[i] = -1;
	}
	
	FOR(i, n) {
		FOR(j, n) {
			int d = vec[i][j];
			if(i < mirow[d]) {
				mirow[d] = i;
			}
			
			if(i > mxrow[d]) {
				mxrow[d] = i;
			}

			if(j < micol[d]) {
				micol[d] = j;
			}
			
			if(j > mxcol[d]) {
				mxcol[d] = j;
			}
		}
	}
	
	vector<int> res(10, 0);
	
	FOR(i, n) {
		vector<int> mp[10];
		
		FOR(j, n) {
			int d = vec[i][j];
			mp[d].phb(j);
		}
		
		FOR(d, 10) {
			if(!mp[d].empty()) {
				int f = mp[d][0], s = mp[d].back();
				
				int base = s  - f;
				int height = max(i, n-1-i);
				
				res[d] = max(res[d], base * height);
				
				base = max(i, n-1-i);
				
				height = max(abs(micol[d] - f), abs(micol[d]-s));
				height = max(height, max(abs(mxcol[d] - f), abs(mxcol[d]-s)));
				
				res[d] = max(res[d], base * height);
			}
		}
	}
	
	FOR(i, n) {
		vector<int> mp[10];
		
		FOR(j, n) {
			int d = vec[j][i];
			mp[d].phb(j);
		}
		
		FOR(d, 10) {
			if(!mp[d].empty()) {
				int f = mp[d][0], s = mp[d].back();
				
				int base = s  - f;
				int height = max(i, n-1-i);
				
				res[d] = max(res[d], base * height);
				
				base = max(i, n-1-i);
				
				height = max(abs(mirow[d] - f), abs(mirow[d]-s));
				height = max(height, max(abs(mxrow[d] - f), abs(mxrow[d]-s)));
				
				res[d] = max(res[d], base * height);
			}
		}
	}
	
	FORV(v, res) {
		cout << v << " ";
	}
	
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}

