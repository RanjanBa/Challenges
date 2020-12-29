#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define rep(i,s,x,inc) for(int i = s; i < x; i+=inc)
#define repr(i,e,x,dec) for(int i = x - 1; i >= e; i-=dec)
#define repv(v, li) for(auto v : li)
#define sz(li) (int)li.size()
#define all(v) v.begin() , v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li,v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
	repv(v, li) {
		cout << v << " ";
	}
	
	cout << "\n";
}

template<typename T>
inline void debug(vector<vector<T>> li) {
	repv(v1, li) {
		repv(v2, v1) {
			cout << v2 << " ";
		}
		
		cout << "\n";
	}
}

// ------ main function ------

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve() {
	int k; cin >> k;
	vector<int> mo(12);
	rep(i,0,12,1) cin >> mo[i];
	
	sort(all(mo));
	
	int cnt = 0;
	if(k > 0) {
		repr(i,0,12,1) {
			k -= mo[i];
			cnt++;
			if(k <= 0) {
				break;
			}
		}
	}
	if(k <= 0)
		cout << cnt << "\n";
	else
		cout << -1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();	
	
	return 0;
}
