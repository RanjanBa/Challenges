#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
	ll n, d;
	
	cin >> n >> d;
	
	vector<ll> vec(n);
	
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	ll ans = d;
	
	for(int i = n - 1; i >= 0; i--) {
		ans = ans - ans % vec[i];
	}
	
	cout << ans << endl; 
}

int main() {
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
