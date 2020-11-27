#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q, a[mxN * 2];

int query(int l, int r) {
	int res = 2e9;
	r++;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l & 1) {
			res = min(res, a[l]);
			l++;
		}
		
		if(r & 1) {
			r--;
			res = min(res, a[r]);
		}
	}
	
	return res;
}

int main() {
	cin >> n >> q;
	
	memset(a, 0x3f3f3f3f, sizeof(a));
	//cout <<  "test: " << a[0] << endl;
	
	for(int i = 0; i < n; i++) {
		cin >> a[n+i];
	}
	
	for(int i = n-1; i > 0; i--) {
		a[i] = min(a[i << 1],a[i << 1 | 1]);
	}

	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		cout << query(l, r) << endl;
	}
    return 0;
}

