#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
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

void solve() {
	string str;
	cin >> str;
	
	int n = str.size();

	int cnt = 0;
	int res = 0;
	
	map<int, int> mp;
	
	FOR(i, n) {
		if(str[i] == '<') {
			mp[cnt] = i;
			cnt++;
		} else {
			cnt--;
			
			if(cnt == 0)
				res = max(res, i + 1);
			
			if(cnt < 0) {
				break;
			}
		}
	}
	
	cout << res << endl;
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

