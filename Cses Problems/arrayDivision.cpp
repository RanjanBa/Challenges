#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n, k;
	
	cin >> n >> k;
	
	vector<int> v(n);
	
	ll l = 0, h = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i], h += v[i];
		l = max(l, (ll)v[i]);
	}
	
	if(k == 1) {
		cout << h << "\n";
		return 0;
	}
	
	while(l < h) {
		ll m = (l + h) / 2, cs = 0;
		int c = 0;
		for(int i = 0; i < n; i++) {
			if(cs + v[i] > m) {
				c++;
				cs = 0;
			}
			
			cs += v[i];
		}
		c++;
		
		if(c > k) {
			l = m + 1;
		} else {
			h = m;
		}
	}
	
	cout << l << endl;
	
    return 0;
}

