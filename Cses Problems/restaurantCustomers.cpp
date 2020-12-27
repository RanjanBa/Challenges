#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		int a, b;
		
		cin >> a >> b;
		
		m.insert({2* a, 1});
		m.insert({2 * b+1, -1});
	}
	
	int c = 0, ans = 0;
	
	for(auto it = m.begin(); it != m.end(); it++) {
		c += (*it).second;
		ans = max(ans, c);
	}
	
	cout << ans << endl;
	
    return 0;
}

