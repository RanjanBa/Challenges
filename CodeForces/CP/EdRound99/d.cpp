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

const int mxN = 500;

int vec[mxN];

bool is_sorted(int* v, int n) {
	FORS(i, 1, n) {
		if(v[i-1] > v[i]) return false;
	}
	
	return true;
}

void solve() {
	int n, x;
	cin >> n >> x;
	
	FOR(i, n) {
		cin >> vec[i];
	}
	
	int res = 0;
	int i = 0;
	while(!is_sorted(vec, n) && i < n) {
		//int i = 0;
		while(i < n && vec[i] <= x) {
			i++;
		}
		
		if(i < n) {
			int temp = vec[i];
			vec[i] = x;
			x = temp;
			res++;
		}
	}
	
	if(is_sorted(vec, n)) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
	}
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

