#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()

using namespace std;

ll n, k, s;

void solve() {
	cin >> n >> k >> s;
	
	ll res = k + n;
	
	res = min(res, (k - 1 + (k-s) + n - s + 1));
	
	cout << res << endl;
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
