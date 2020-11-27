#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q;
int a[mxN * 2];

void update(int pos, int val) {
	pos = pos + n;
	a[pos] += val;
	
	for(; pos > 0; pos >>= 1) {
		a[pos>>1] = max(a[pos],a[pos^1]);
	}
}

int query(int l, int r) {
	int res = 0;
	
	r++;
	
	for(l += n, r+= n; l < r; l >>= 1, r >>=1) {
		if(l&1) {
			res = max(res, a[l]);
			l++;
		}
		
		if(r&1) {
			r--;
			res = max(res, a[r]);
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
		a[i] = max(a[i << 1], a[i << 1 | 1]);
	}
	
	while(q--) {
		int r;
		cin >> r;
		
		int l = 0, h = n - 1;
		int res = -1;
		while(l <= h) {
			int m = (l + h) / 2;
			
			if(query(0, m) >= r) {
				res = m;
				h = m-1;
			} else {
				l = m + 1;
			}
		}
		
		if(res != -1) {
			update(res, -r);
		}
		
		cout << res+1 << " ";
	}
	
	cout << endl;
}

int main() {
	solve();
	
    return 0;
}

