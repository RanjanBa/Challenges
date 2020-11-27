#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

const int mxN = 2e5;

int v[mxN];

int main() {
	int n, t;
	cin >> n >> t;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	ll l = 1, h = 1e18;
	
	while(l < h) {
		ll m = (l + h) / 2;
		ll p = 0;
		
		for(int i = 0; i < n; i++) {
			p += m /v[i];
			
			if(p >= t) {
				break;
			}
		}
		
		if(p >= t) {
			h = m;
		} else {
			l = m + 1;
		}
	}
	
	cout << l << endl;
	
    return 0;
}

