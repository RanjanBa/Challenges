#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q, a[mxN], pre[mxN+1];

int main() {
	cin >> n >> q;
	
	set<int> st;
	
	pre[0] = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		
		st.insert(a[i]);
		pre[i+1] = st.size();
		cout << pre[i+1] << " ";
	}
	
	cout << endl;
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		cout << pre[r] - pre[l-1] << endl;
	}
	
    return 0;
}

