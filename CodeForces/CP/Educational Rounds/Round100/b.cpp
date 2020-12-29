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
#define blt_clz __builtin_clz

using namespace std;

template<typename T>
inline void print(vector<T> li) {
	repv(v, li) {
		cout << v << " ";
	}
	
	cout << "\n";
}

template<typename T>
inline void print(vector<vector<T>> li) {
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
	int n = 0;
	cin >> n;
	
	ll res[n];
	//ll ev_s = 0, od_s = 0;
	mem(res, 0);
	rep(i, 0, n, 1) {
		cin >> res[i];
		//if(i&1) {
			//od_s += res[i];
		//} else {
			//ev_s += res[i];
		//}
	}
	
	
	
	rep(i,0,n,1) {
		ll k = log2l(res[i]);
		res[i] = powl(2, k);
	}
	
	
	// set all odd indices to 1 if sum of odd indices is greater than equal to sum of even indices and vice versa;
	
	//int s = 0;
	//if(od_s < ev_s) {
		//s = 1;
	//}
	
	//rep(i,s,n,2) {
		//res[i] = 1;
	//}
	
	rep(i,0,n,1) {
		cout << res[i] << " ";
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

