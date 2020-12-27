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

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve() {
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

