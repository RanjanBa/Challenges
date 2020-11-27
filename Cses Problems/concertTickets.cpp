#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n, m;
	
	cin >> n >> m;
	
	set<array<int, 2>> s;
	
	for(int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		s.insert({a, i});
	}
	
	for(int i = 0; i < m; i++) {
		int b = 0;
		cin >> b;
		
		auto it = s.lower_bound({b+1, 0});
		
		if(it == s.begin()) {
			cout << "-1" << endl;
		} else {
			--it;
			cout << (*it)[0] << endl;
			s.erase(it);
		}
	}
	
    return 0;
}

