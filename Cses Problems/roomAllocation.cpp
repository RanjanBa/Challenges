#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<ar<int, 3>> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i][1] >> v[i][0];
		v[i][2] = i;
	}
	
	sort(v.begin(), v.end());
	
	map<ar<int, 2>, int> mp;
	vector<int> ans(n);
	
	for(int i = 0; i < n; i++) {
		auto it = mp.lower_bound({v[i][1]});
		int p = 0;
		if(it != mp.begin()) {
			--it;
			p = it->second;
			mp.erase(it);
		} else {
			p = mp.size() + 1;
		}
		
		mp[{v[i][0], i}] = p;
		ans[v[i][2]] = p;
	}
	
	cout << mp.size() << endl;
	
	for(int i: ans) {
		cout << i << " ";
	}
	
	cout << endl;
	
    return 0;
}

