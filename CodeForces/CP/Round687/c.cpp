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
#define INF 1e9
#define INFL 1e18

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

const int mxN = 1e5+10;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int vec[mxN];
int dp[mxN];

void solve() {
	int n, p, k;
	cin >> n >> p >> k;
	string str;
	cin >> str;
	
	FORS(i, 1, n+1) {
		vec[i] = str[i-1] == '1' ? 0 : 1;
	}
	
	int x, y;
	cin >> x >> y;
	
	FORR(i, n+1) {
		if(i == 0) continue;
		
		if(i + k > n) {
			dp[i] = vec[i];
		} else {
			dp[i] = dp[i+k] + vec[i];
		}
	}
	
	ll res = INFL;
	FOR(i,n) {
		if(i+p > n) {
			break;
		}
		
		res = min(res, (i * 1ll * y + x * 1ll * dp[i+p]));
	}
	
	cout << res << endl;
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

