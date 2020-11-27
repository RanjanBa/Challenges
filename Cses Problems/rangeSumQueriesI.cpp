#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 2e5;

int n, q;
ll a[mxN + 1];

int main() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		a[i] = a[i-1] + t;
	}
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		cout << a[r] - a[l-1] << endl;
	}
	
    return 0;
}

