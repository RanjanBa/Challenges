#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define arr array

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n;
	
	cin >> n;
	
	oset<arr<int,2>> st;

	for(int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;

		st.insert({i, a});
	}

	for(int i = 0; i < n; i++) {
		int p;
		cin >> p, p--;

		auto it = st.find_by_order(p);
		
		cout << (*it)[1] << " ";
		st.erase(it);
	}

	cout << endl;
}
