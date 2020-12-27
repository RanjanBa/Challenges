#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	
	ll ans = 0, prev = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		if(i == 0) {
			prev = a;
		} else {
			if(prev > a) {
				ans += (prev - a);
			} else {
				prev = a;
			}
		}
	}
	
	cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}

