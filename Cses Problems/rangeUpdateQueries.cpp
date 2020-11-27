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
	ll s;
	ll lz;
} st[1<<19];

void build(int idx, int l, int r) {
	if(l > r) return;
	
	if(l == r) { 
		st[idx].s = a[l];
		return;
	}
	
	int m = l + (r - l) / 2;
	
	build(2 * idx + 1, l, m);
	build(2 * idx + 2, m+1, r);
	
	st[idx].s = st[2*idx+1].s + st[2*idx+2].s;
}

void rangeUpdate(int idx, int val, int l, int r, int ql, int qr) {
	if(st[idx].lz != 0) {
		st[idx].s += (r - l + 1) * st[idx].lz;
		
		if(l != r) {
			st[idx * 2 + 1].lz += st[idx].lz;
			st[idx * 2 + 2].lz += st[idx].lz;
		}
		
		st[idx].lz = 0;
	}
	
	if(l > r || l > qr || r < ql) return;
	
	if(ql <= l && r <= qr) {
		st[idx].s += (r - l + 1) * val;
		
		if(l != r) {
			st[idx * 2 + 1].lz += val;
			st[idx * 2 + 2].lz += val;
		}
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	rangeUpdate(idx * 2 + 1, val, l, m, ql, qr);
	rangeUpdate(idx * 2 + 2, val, m+1, r, ql, qr); 
	
	st[idx].s = st[idx * 2 + 1].s + st[idx * 2 + 2].s;
}

ll query(int idx, int l, int r, int ql, int qr) {
	if (st[idx].lz != 0) 
    { 
        st[idx].s += (r-l+1)*st[idx].lz; 

        if (l != r) 
        {
            st[idx*2 + 1].lz += st[idx].lz; 
            st[idx*2 + 2].lz += st[idx].lz; 
        } 
        
        st[idx].lz = 0; 
    } 
  
    if(l > r || l > qr || r < ql)
        return 0; 
  
    if (ql <= l && r <= qr) 
        return st[idx].s; 
  
    int m = l + (r - l)/2; 
    return query(2 * idx + 1, l, m, ql, qr) + 
           query(2 * idx + 2, m+1, r, ql, qr); 
}

void solve() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	build(0, 0, n-1);
	
	//for(int i = 0; i < 2 * n; i++) {
		//cout << st[i].s << " ";
	//}
	
	//cout << endl;
	
	while(q--) {
		int t;
		cin >> t;
		
		if(t == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			l--, r--;
			rangeUpdate(0, val, 0, n-1, l, r);
		} else {
			int pos;
			cin >> pos;
			pos--;
			cout << query(0, 0, n-1, pos, pos) << endl;
		}
	}
}

int main() {
	solve();
	
    return 0;
}

