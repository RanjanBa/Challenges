#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v(n);
	
	for(int i = 0;  i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	int x = v[n/2];
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++) {
		ans += abs(v[i] - x);
	}
	
	cout << ans << endl;
	
    return 0;
}

