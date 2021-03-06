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

const int mxN = 2e5 + 10;

arr<int, 2> vec[mxN];

void solve() {
	int n;
	cin >> n;
	
	FOR(i, n) {
		cin >> vec[i][1];
	}
	
	FOR(i, n) {
		cin >> vec[i][0];
	}
	
	sort(vec, vec+n);
	
	ll res = 0;
	
	int l = n;
	
	FOR(i, n) {
		int f = min(vec[i][1], l);
		
		l -= f;
		
		res += f * 1ll * vec[i][0];
		
		if(l == 0) break;
	}
	
	cout << res << endl;
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

