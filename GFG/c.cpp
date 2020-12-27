#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	
    string a, b;
	cin >> a >> b;
	
	int res = 0;
	
	cout << a << ", " << b << endl;
	for(int i = 0; i < n; i++) {
	    for(int j = i; j < n; j++) {
	        string str1 = a.substr(i, j - i + 1);
	        
	        int len = str1.size();
	        
	        //if(len > m) break;
	        
	        for(int k = 0; k <= m - len; k++) {
	            string str2 = b.substr(k, len);
	            
	            if(str2 == str1) {
	                res = max(res, len);
	            }
	        }
	    }
	}
	
	cout << res << "\n";
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    solve();
	}
	
	return 0;
}
