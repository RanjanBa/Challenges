#include<bits/stdc++.h>
#define unint unsigned int
#define ll long long
#define ld long double

using namespace std;

template<class A> void dbg(vector<A> &v) {
	int size = v.size();
	if(size == 0) return;
		
	for(int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class A> void dbg(vector<A> &v, int size) {
	if(size == 0) return;
	
	for(int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class A> void dbg(vector<vector<A>> &v) {
	int size = v.size();
	if(size == 0) return;
	
	for(int i = 0; i < size; i++) {
		dbg(v[i], v[i].size());
	}
}

template<class A> void dbg(vector<vector<A>> &v, int size) {
	if(size == 0) return;
	
	for(int i = 0; i < size; i++) {
		dbg(v[i], v[i].size());
	}
}

const int mxN = 5e5;

int n, a, b, cntA[mxN], cntB[mxN];
vector<vector<int>> g(mxN);
ld ans = 0.0;

void dfs(int u = 0, int d = 0) {
	int prevA = cntA[d%a], prevB = cntB[d%b];
	cntA[d%a]++;
	cntB[d%b]++;
	
	for(int v: g[u])
		dfs(v, d + 1);
	
	int lastA = cntA[d%a], lastB = cntB[d%b];
	
	ans+=(ld)(lastA-prevA)/n;
    ans+=(ld)(lastB-prevB)/n;
    ans-=(ld)(lastA-prevA)*(ld)(lastB-prevB) / n / n;
}

void solve() {
    cin >> n >> a >> b;
    
    for(int i = 1; i <= n - 1; i++) {
		int u;
		cin >> u, u--;
		
		g[u].push_back(i);
	}
	
	ans = 0.0;
	memset(cntA, 0, n * 4);
	memset(cntB, 0, n * 4);
	
	dfs();
	
	cout << fixed << setprecision(9);
    cout << ans << endl;
    
    for(int i = 0; i < n; i++)
		g[i].clear();
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
