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

const int mxN = 1e6;

int vec[mxN];

void solve() {
	int n;
	cin >> n;
	
	stack<int> st;
	
	FOR(i, n) {
		cin >> vec[i];
		if(st.size()) {
			if(vec[i] < vec[st.top()]) {
				st.push(i);
			}
		} else {
			st.push(i);
		}
	}
	
	ll ans = 0;
	
	int mx = 0;
	
	FORR(i, n) {
		while(st.top() > i) {
			st.pop();
		}
		
		int d = vec[st.top()] - mx;
		//cout << i << ": " << vec[st.top()] <s< ", d: " << d << endl;
		ans += ((ll)d * (i + 1));
		mx = vec[st.top()];
	}
	
	cout << ans << endl;
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

