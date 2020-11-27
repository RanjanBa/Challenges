#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
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


void solve() {
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	int ga = 0, gb = 0;
	int rema = n, remb = n;
	FOR(i, 2 * n) {
		int idx = i + 1;
		if(idx & 1) {
			ga += str[i] == '1' ? 1 : 0;
			rema--;
		} else {
			gb += str[i] == '1' ? 1 : 0;
			remb--;
		}
		
		if(ga > gb) {
			int d = ga - gb;
			if(d > remb) {
				cout << idx << endl;
				return;
			}
		} else if(ga < gb){
			int d = gb - ga;
			if(d > rema) {
				cout << idx << endl;
				return;
			}
		}
	}
	
	cout << 2 * n << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        //cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

