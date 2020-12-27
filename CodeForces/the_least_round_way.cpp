// Not completed

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

// ------ main function ------

const int mxN = 1000;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int count(int n, int d) {
	int cnt = 0;
	while(n % d == 0) {
		cnt++;
		n /= d;
	}
	
	return cnt;
}

int dp1[mxN][mxN];
int dp2[mxN][mxN];

char path1[mxN][mxN];
char path2[mxN][mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	cin >> n;
	
	FOR(i, n) {
		FOR(j, n) {
			int a;
			cin >> a;
			
			dp[i][j] = count(a);
			path[i][j] = '.';
		}
	}
	
	FOR(i, n) {
		FOR(j, n) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	
	FOR(i, n) {
		FOR(j, n) {
			if(i == 0 && j == 0) continue;
			
			if(i == 0) {
				dp[i][j] += dp[i][j-1];
				path[i][j] = 'R';
			} else if(j == 0) {
				dp[i][j] += dp[i-1][j];
				path[i][j] = 'D';
			} else {
				dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
				
				char ch;
				if(dp[i-1][j] <= dp[i][j-1]) {
					ch = 'D';
				} else {
					ch = 'R';
				}
				
				path[i][j] = ch;
			}
		}
	}
	
	FOR(i, n) {
		FOR(j, n) {
			cout << path[i][j] << " ";
		}
		
		cout << "\n";
	}
	
	cout << dp[n-1][n-1] << "\n";
	
	string res;
	
	int r = n - 1, c = n - 1;
	while(r != 0 || c != 0) {
		res += path[r][c];
		if(path[r][c] == 'D') {
			r--;
		} else {
			c--;
		}
	}
	
	FORR(i, SZ(res)) {
		cout << res[i];
	}
	
	cout << "\n";
	
	return 0;
}
