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

const int mxN = 1e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int vec[mxN];

void solve() {
	int n, k;
	
	cin >> n >> k;
	
	FOR(i, n) {
		cin >> vec[i];
	}
	
	int i = 0;
	
	for(int l = k; l > 0 && i < n-1; l--) {
		bool flag = false;
		
		int p = 0;
		
		while((1 << (p+1)) <= vec[i]) {
			p++;
		}
		
		int r = 1 << p;
		
		//cout << p << "";
		
		vec[i] = vec[i] ^ r;
		
		FOR(j, n) {
			int x = vec[j]^r;
			if(x < vec[j]) {
				vec[j] = x;
				flag = true;
				break;
			}
		}
		
		if(!flag) {
			vec[n-1] = vec[n-1]^r;
		}
		
		while(vec[i] <= 0) {
			i++;
		}
		
		int z = l + 1;
		
		if(z > 0) {
			if(n < 3 && (z % 2) == 0) {
				vec[n-1] = vec[n-1]^1;
				vec[n-2] = vec[n-2]^1;
			}
		}
	}
	
	FOR(j, n) {
		cout << vec[j] << " ";
	}
	
	cout << "\n";
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

