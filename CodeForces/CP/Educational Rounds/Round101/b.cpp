#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define rep(i,s,x,inc) for(int i = s; i < x; i+=inc)
#define repr(i,e,x,dec) for(int i = x - 1; i >= e; i-=dec)
#define repv(v, li) for(auto v : li)
#define sz(li) (int)li.size()
#define all(v) v.begin() , v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li,v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
	repv(v, li) {
		cout << v << " ";
	}
	
	cout << "\n";
}

template<typename T>
inline void debug(vector<vector<T>> li) {
	repv(v1, li) {
		repv(v2, v1) {
			cout << v2 << " ";
		}
		
		cout << "\n";
	}
}

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	
	rep(i,0,n,1) {
		cin >> a[i];
	}
	
	int m; cin >> m;
	vector<int> b(m);
	rep(i,0,m,1) {
		cin >> b[i];
	}
	
	int res = max(0, a[0]);
	
	rep(i,1,n,1) {
		a[i] = a[i] + a[i-1];
		res = max(res, a[i]);
	}
	
	res = max(res, b[0]);
	
	rep(i,1,m,1) {
		b[i] = b[i] + b[i-1];
		res = max(res, b[i]);
	}
	
	rep(i,0,n,1) {
		rep(j,0,m,1) {
			int sum = a[i] + b[j];
			res = max(res, sum);
		}
	}
	
	rep(i,0,m,1) {
		rep(j,0,n,1) {
			int sum = b[i] + a[j];
			res = max(res, sum);
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

