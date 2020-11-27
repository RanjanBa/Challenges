#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define arr array

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 2e5;

int n, q, a[mxN];

int main() {
	cin >> n >> q;
	
	oset<arr<int,2>> st;

	for(int i = 0; i < n; i++) {
		cin >> a[i];

		st.insert({a[i], i});
	}

	while(q--) {
		char ch;
		cin >> ch;
		
		if(ch == '!') {
			int k, x;
			cin >> k >> x;
			k--;
			
			st.erase({a[k], k});
			
			a[k] = x;
			st.insert({a[k], k}); 
		} else {
			int x, y;
			cin >> x >> y;
			int cnt = st.order_of_key({y+1, 0}) - st.order_of_key({x, 0});
			
			cout << cnt << endl;
		}
	}
	
	return 0;
}
