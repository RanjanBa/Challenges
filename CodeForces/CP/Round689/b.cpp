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

const int mxN = 505;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int dp[mxN][mxN];

void solve() {
	int n, m;
	cin >> n >> m;
	
	memset(dp, 0, sizeof(dp));
	
	FORS(i,1, n+1) {
		string str;
		cin >> str;
		FORS(j,1, m+1) {
			dp[i][j] = str[j-1] == '*' ? 1 : 0;
		}
	}
	
	FORS(k, 2, n+1) {
		FORS(i, k, n+1) {
			FORS(j,k, m-k+2) {
				if(dp[i][j] == 0) continue;
				
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i][j+1])) + 1;
			}
		}
	}
	
	int res = 0;
	FORS(i,1, n+1) {
		FORS(j,1,m+1) {
			res += dp[i][j];
		}
	}
	
	cout << res << "\n";
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

