#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int x, n, a;
	
	cin >> x >> n;
	
	set<int> s;
	map<int, int> mp;
	
	s.insert(0);
	s.insert(x);
	
	mp[x] = 1;
	
	for(int i = 0; i < n; i++) {
		cin >> a;
		
		auto it = s.lower_bound(a);
		
		int r = *it;
		--it;
		int l = *it;
		
		--mp[r - l];
		if(!mp[r-l]) {
			mp.erase(r- l);
		}
		
		s.insert(a);
		
		mp[r - a]++;
		mp[a - l]++;
		
		cout << (--mp.end())->first << " ";
	}
	
	cout << endl;
	
    return 0;
}

