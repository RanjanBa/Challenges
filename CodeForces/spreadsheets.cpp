#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	while(n--) {
		string s;
		cin >> s;
		
		int r = 0, c = 0;
		
		if(s[0] == 'R') {
			string ts;
			for(int i = 1; i < (int)s.size(); i++) {
				if(s[i] == 'C') {
					stringstream stStream(ts);
					stStream >> r;
					ts = "";
				} else {
					ts+= s[i];
				}
			}
			if(ts.size()) {
				stringstream stStream(ts);
				stStream >> c;
			}
		}
		string ans;
		if(r != 0 && c != 0) {
			while(c) {
				int q = c % 26;
				if(q == 0) {
					q = 26;
				}
				c -= q;
				q--;
				
				ans = (char)('A' + q) + ans;
				c = c / 26;
			}
			ans += to_string(r);
		} else {
			string ts, rs;
			for(int i = 0; i < (int)s.size(); i++) {
				if(s[i] >= '0' && s[i] <= '9') {
					rs += s[i];
				} else {
					ts += s[i];
				}
			}
			stringstream stStream(rs);
			stStream >> r;
			c = 0;
			for(int i = ts.size() - 1, k = 0; i >= 0; i--, k++) {
				int p = pow(26, k);
				int t = ts[i] - 'A' + 1;
				c += p * t;
			}
			ans = 'R';
			ans += to_string(r);
			ans +='C';
			ans += to_string(c);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
