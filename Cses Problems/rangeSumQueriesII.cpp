#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q;
ll a[mxN * 2];

void update(int pos, int val) {
	pos = pos + n;
	a[pos] = val;
	
	for(; pos > 0; pos >>= 1) {
		a[pos>>1] = a[pos] + a[pos^1];
	}
}

ll query(int l, int r) {
	ll res = 0;
	
	r++;
	
	for(l += n, r+= n; l < r; l >>= 1, r >>=1) {
		if(l&1) {
			res += a[l];
			l++;
		}
		
		if(r&1) {
			r--;
			res += a[r];
		}
	}
	
	return res;
}

void solve() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	
	for(int i = 0; i < n; i++) {
		cin >> a[n+i];
	}
	
	for(int i = n-1; i > 0; i--) {
		a[i] = a[i << 1] + a[i << 1 | 1];
	}
	
	while(q--) {
		int t;
		cin >> t;
		
		if(t == 1) {
			int k, val;
			cin >> k >> val;
			k--;
			update(k, val);
		} else {
			int l, r;
			cin >> l >> r;
			l--, r--;
			cout << query(l, r) << endl;
		}
	}
}

int main() {
	solve();
	
    return 0;
}

