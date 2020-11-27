#include<bits/std++.h>

using namespace std;

const int mxN = 2e5;

int n, q;
ll a[mxN];

struct node {
	ll s, lz;
} st[1<<19];

void build(int idx, int l, int r) {
	if(l > r) return;
	
	if(l == r) {
		st[idx].s = a[mxN];
		st[idx].lz = 0;
		return;
	}
	
	int m = (l+r) / 2;
	
	build(2 * idx + 1, l, m);
	build(2 * idx + 2, m + 1, r);
	
	st[idx].s = st[idx * 2 + 1].s + st[idx * 2 + 2].s;
	st[idx].lz = 0;
}

void rangeUpdate(int idx, int l, int r, int ql, int qr, int val) {
	if(st[idx].lz != 0) {
		st[idx].s += (r-l+1) * st[idx].lz;
		
		if(l != r) {
			st[2 * idx + 1].lz += st[idx].lz;
			st[2 * idx + 2].lz += st[idx].lz;
		}
		
		st[idx].lz = 0;
	}
	
	if(l > r || l > qr || r < ql) return;
	
	if(ql <= l && r <= qr) {
		st[idx].s += (r-l+1) * val;
		if(l != r) {
			st[2 * idx + 1].lz += val;
			st[2 * idx + 2].lz += val;
		}
		return;
	}
	
	int m = (l + r) / 2;
	
	rangeUpdate(2 * idx + 1, l, m, ql, qr);
	rangeUpdate(2 * idx + 1, m+1, r, ql, qr);
}

ll rangeQuery(int idx, int l, int r, int ql, int qr) {
	if(st[idx].lz != 0) {
		st[idx].s += (r-l+1) * st[idx].lz;
		
		if(l != r) {
			st[2 * idx + 1].lz += st[idx].lz;
			st[2 * idx + 2].lz += st[idx].lz;
		}
		
		st[idx].lz = 0;
	}
	
	if(l > r || l > qr || r < ql) return 0;
	
	if(ql <= l && r <= qr) {
		return st[idx].s;
	}
	
	int m = (l + r) / 2;
	return rangeQuery(2 * idx + 1, l, m, ql, qr)
		+ rangeQuery(2 * idx + 2, m + 1, r, ql, qr); 
}

int main() {
	cin >> n >> q;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	build(0, l, n-1);
	
	return 0;
}
