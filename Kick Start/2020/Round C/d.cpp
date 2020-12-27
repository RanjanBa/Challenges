#include<bits/stdc++.h>
#define ll long long
#define arr array

using namespace std;

const int mxN = 2e5;

ll vec[mxN];

struct Node {
	ll sum;
	ll sumMult;
	Node(ll _sum, ll _sumMult): sum(_sum), sumMult(_sumMult) {};
	
	void updateSum(ll _sum, ll _sumMult) {
		sum = _sum;
		sumMult = _sumMult;
	}
};

class SegmentTree {
private:
	Node* nodes[2 * mxN];
	int n;
	
	void _update(ll newVal, int idx) {
		nodes[n+idx]->updateSum(newVal, (idx + 1) * newVal);
		
		idx += n;
		
		for(int i = idx; i > 1; i >>= 1) {
			ll res1 = 0, res2 = 0;
			int l = i, r = i^1;
			if(nodes[l] != NULL) {
				res1 += nodes[l]->sum;
				res2 += nodes[l]->sumMult;
			}
			
			if(nodes[r] != NULL) {
				res1 += nodes[r]->sum;
				res2 += nodes[r]->sumMult;
			}
			
			nodes[i>>1]->updateSum(res1, res2);
		}
	}
	
	ll _query(int l, int r) {
		ll res = 0;
		int mult = l;
		r++;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				res += nodes[l]->sumMult - mult * nodes[l]->sum;
				l++;
			}
			
			if(r & 1) {
				r--;
				res += nodes[r]->sumMult - mult * nodes[r]->sum;
			}
		}
		
		return res;
	}
	
public:
	SegmentTree(int _n) {
		n = _n;
		for(int i = 0; i < _n; i++) {
			nodes[n+i] = new Node(vec[i], vec[i] * (i + 1));
		}
		
		for(int i = n - 1; i > 0; i--) {
			ll res1 = 0, res2 = 0;
			int l = i << 1;
			if(nodes[l] != NULL) {
				res1 = nodes[l]->sum;
				res2 = nodes[l]->sumMult;
			}
			
			int r = i << 1 | 1;
			if(nodes[r] != NULL) {
				res1 += nodes[r]->sum;
				res2 += nodes[r]->sumMult;
			}
			
			nodes[i] = new Node(res1, res2);
		}
	}
	
	void update(ll val, int idx) {
		_update(val, idx);
		vec[idx] = val;
	}
	
	ll query(int l, int r) {
		return _query(l, r);
	}
	
	void print() {
		cout << "Array " << 2 * n << ": ";
		for(int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		
		cout << "\nTree " << 2 * n << ": ";		
		for(int i = 0; i < 2 * n; i++) {
			if(nodes[i] == NULL) {
				cout << "NULL";
			} else {
				cout << nodes[i]->sum;
			}
			
			if(i < 2 * n - 1) cout << ", ";
		}
		
		cout << "\nTree Mult " << 2 * n << ": ";
		for(int i = 0; i < 2 * n; i++) {
			if(nodes[i] == NULL) {
				cout << "NULL";
			} else {
				cout << nodes[i]->sumMult;
			}
			
			if(i < 2 * n - 1) cout << ", ";
		}
		
		cout << endl;
	}
};

void solve() {
	int n, q;
	
	cin >> n >> q;
	
	//vector<ll> vec(n);
	
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
		if(i & 1) vec[i] *= -1;
	}
	
	SegmentTree *tree = new SegmentTree(n);
	
	//tree->print();
	
	ll res = 0;
	
	while(q--) {
		char ch;
		cin >> ch;
		if(ch == 'U') {
			int idx, val;
			cin >> idx >> val;
			--idx;
			
			if(idx & 1) {
				val *= -1;
			}
			
			tree->update(val, idx);
			//tree->print();
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			
			ll t = tree->query(l, r);

			if(l & 1) t *= -1;
			
			//cout << ch << ", t : " << t << endl;
			
			res += t;
		}
	}
	
	cout << res << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

