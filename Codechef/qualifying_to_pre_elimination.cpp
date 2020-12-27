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

const int mxN = 1e5;
int vec[mxN];

bool com(const int a, const int b) {
	if(a < b) return false;
	
	return true;
}

void solve() {
	int n, k;
	
	cin >> n >> k;
	k--;
	
	FOR(i, n) {
		cin >> vec[i];
	}
	
	sort(vec, vec + n);
	reverse(vec, vec + n);
	
	int l = 0, r = n-1, index = -1;
	while(l <= r) {
		int m = (l + r) >> 1;
		
		if(vec[m] == vec[k]) {
			index = m;
			l = m + 1;
		} else if(vec[m] > vec[k]) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	cout << index + 1 << endl;
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

