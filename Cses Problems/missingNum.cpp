#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n;
	
	cin >> n;
	
	ll sum = (ll)n * (n + 1) / 2;
	
	for(int i = 0; i < n - 1; i++) {
		ll a;
		cin >> a, sum -= a;
	}
	
	cout << sum << endl;
}

int main() {
    solve();
    return 0;
}

