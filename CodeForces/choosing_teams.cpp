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

const int mxN = 2000;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int vec[mxN];

void solve() {
	int n, k;
	cin >> n >> k;
	
	rep(i,0,n,1) {
		cin >> vec[i];
	}
	
	int teams = 0;
	int num = 0;
	
	//rep(i,0,5,1) {
		rep(j,0,n,1) {
			vec[j] += k;
			if(vec[j] <= 5) {
				num++;
			}

			if(num == 3) {
				teams++;
				num = 0;
			}
		}
	//}
	
	cout << teams << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();	
	
	return 0;
}
