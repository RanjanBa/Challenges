#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q, a[2 * mxN];

int query(int l, int r) {
	int res = a[n+l];
	l++;
	r++;
	for(l += n, r += n; l < r; l >>= 1 , r >>= 1) {
		if(l&1) {
			res ^= a[l];
			l++;
		}
		
		if(r&1) {
			r--;
			res ^= a[r];
		}
	}
	
	return res;
}

int main() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	
	for(int i = 0; i < n; i++) {
		cin >> a[n+i];
	}
	
	for(int i = n-1; i > 0; i--) {
		a[i] = a[i<<1] ^ a[i<<1|1];
	}

	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		cout << query(l, r) << endl;
	}
	
    return 0;
}

