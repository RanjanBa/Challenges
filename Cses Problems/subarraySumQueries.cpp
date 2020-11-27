#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q;
ll a[mxN];

struct node {
	ll s, mx, mxl, mxr;
} st[1<<19];

void update(int idx, int pos, int val, int l = 0, int r = n-1) {
	if(l == r) { 
		st[idx].s = st[idx].mxl = st[idx].mxr = val;
		st[idx].mx = max(val, 0);
		return;
	}
	
	int m = l + (r - l) / 2;
	
	if(pos <= m)
		update(2 * idx + 1, pos, val, l, m);
	else
		update(2 * idx + 2, pos, val, m+1, r);
	
	st[idx].s = st[2*idx+1].s + st[2*idx+2].s;
	st[idx].mx = max({st[2*idx+1].mx, st[2*idx+2].mx, st[2*idx+1].mxr + st[2*idx+2].mxl, 0ll});
	
	st[idx].mxl = max(st[2*idx+1].mxl, st[2*idx+1].s + st[2*idx+2].mxl);
	st[idx].mxr = max(st[2*idx+2].mxr, st[2*idx+2].s + st[2*idx+1].mxr);
}

void solve() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		update(0, i, a[i]);
	}

	while(q--) {
		int k, x;
		
		cin >> k >> x;
		
		k--;
		
		update(0, k, x);
		
		cout << st[0].mx << endl; 
	}
}

int main() {
	solve();
	
    return 0;
}

