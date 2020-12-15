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
#define mem(li,v) memset(li, v, sizeof(li))
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

const int mxN = 1e5 + 10;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int n, q;
ll vec[mxN];
set<ll> sums;
ll prefix[mxN];

//void split(int i, int j) {
	//if(j < i) return;
	
	//ll s = prefix[j];
	//if(i > 0) {
		//s -= prefix[i-1];
	//}
	
	//sums.insert(s);
	
	//cout << i << ", " << j << ", sum: " << s << endl;
	//if(vec[i] == vec[j]) return;
	//if(i == j) return;
	
	//ll mid = (vec[i] + vec[j]) / 2;
	//int pos = upper_bound(vec, vec+n, mid) - vec;
	
	//if(pos > j) {
		//return;
	//}
	//cout << i << ", " << j << ", mid: " << mid << ", pos: " << pos << endl;
	//split(i, pos-1);
	//split(pos, j);
//}

//void split(int i, int j) {
	//if(j < i) return;
	
	//ll s = prefix[j];
	//if(i > 0) {
		//s -= prefix[i-1];
	//}
	
	//sums.insert(s);
	//cout << i << ", " << j << ", sum: " << s << endl;
	
	//if(i == j) return;
	//if(vec[i] == vec[j]) return;
	
	//ll mid = (vec[i] + vec[j]) / 2;
	
	//int pos = upper_bound(vec, vec+j, mid) - vec;
	
	//cout << i << ", " << j << ", mid: " << mid << ", pos: " << pos << endl;
	//split(i, pos-1);
	//split(pos, j);
//}

void split(int i, int j) {
	if(j < i) return;
	
	ll s = prefix[j];
	if(i > 0) {
		s -= prefix[i-1];
	}
	
	sums.insert(s);
	//cout << i << ", " << j << ", sum: " << s << endl;
	
	if(i == j) return;
	
	ll mid = (vec[i] + vec[j]) / 2;
	
	int pos = upper_bound(vec, vec+j+1, mid) - vec;
	if(pos-1 == j) return;
	//cout << i << ", " << j << ", mid: " << mid << ", pos: " << pos << endl;
	split(i, pos-1);
	split(pos, j);
}

void solve() {
	cin >> n >> q;
	
	FOR(i, n) {
		cin >> vec[i];
	}
	
	sort(vec, vec+n);
	
	FOR(i, n) {
		if(i) {
			prefix[i] = vec[i] + prefix[i-1];
		} else {
			prefix[i] = vec[i];
		}
	}
	
	split(0, n-1);
	
	while(q--) {
		int a;
		cin >> a;
		
		if(sums.find(a) != sums.end()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	memset(vec, 0, sizeof(vec));
	memset(prefix, 0, sizeof(prefix));
	sums.clear();
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

