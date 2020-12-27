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
	ll n;
	cin >> n;
	
	vector<arr<ll, 2>> pfac;
	
	for(ll i = 2; i * i <= n; i++) {
		int cnt = 0;
		while(n % i == 0) {
			cnt++;
			n /= i;
		}
		
		if(cnt) {
			pfac.push_back({cnt, i});
		}
		
	}
	
	if(n > 1) {
		pfac.push_back({1, n});
	}
	
	//cout << "nn2: " << n << ", si: " << pfac.size() << endl;
	sort(pfac.begin(), pfac.end());
	
	int m = pfac.size();
	
	cout << pfac[m-1][0] << endl;
	
	while(pfac[m-1][0] > 1) {
		cout << pfac[m-1][1] << " ";
		pfac[m-1][0]--;
	}
	ll res = 1;
	for(int i = 0; i < m; i++) {
		res *= pow(pfac[i][1], pfac[i][0]);
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

