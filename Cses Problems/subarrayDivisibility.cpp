#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n, a;
	
	cin >> n;
	
	ll pref = 0, ans = 0;
	map<ll, int> mp;
	mp[pref]++;
	for(int i = 0; i < n; i++) {
		cin >> a;
		pref = (pref + a % n + n) % n;
		ans += mp[pref];
		mp[pref]++;
	}
	
	cout << ans << endl;
	
    return 0;
}

