#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	
	int n = s.size();
	char pc = s[0];
	int c = 1, ans = 1;
	for(int i = 1; i < n; i++) {
		if(pc == s[i]) {
			c++;
			ans = max(ans, c);
		} else {
			pc = s[i];
			c = 1;
		}
	}
	
	cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}

