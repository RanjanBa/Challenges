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

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int vec[mxN];

void solve() {
	int n;
	cin >> n;
	
	FOR(i, n) {
		cin >> vec[i];
	}
	
	// calculate sum of absolute differences between adjacent elements
	ll diff = 0;
	
	FORS(i,1, n) {
		diff += abs(vec[i] - vec[i-1]);
	}
	
	ll res = diff;
	
	FOR(i, n) {
		ll temp = diff;
		if(i == 0) {
			// make first element is equal to second
			temp -= abs(vec[i] - vec[i+1]);
		} else {
			// make current element equal to previous element
			// substracting abs diff between current element and previous element
			temp -= abs(vec[i] - vec[i-1]);
			if(i < n-1)  {
				// remove abs diff betwenn current element and next element
				temp -= abs(vec[i] - vec[i+1]);
				// adding abs diff between previous (i-1) and next element (i+1)
				temp += abs(vec[i-1] - vec[i+1]);
			}
		}
		
		res = min(res, temp);
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

