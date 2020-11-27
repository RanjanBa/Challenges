#include<bits/stdc++.h>
#define ll long long
#define ar array
#define phb push_back
#define ppb pop_back
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int d = v[1] - v[0];
	int c = 2, ans = 2;
	for(int i = 2; i < n; i++) {
		if(v[i] - v[i-1] == d) {
			c++;
			ans = max(ans, c);
		} else {
			d = v[i] - v[i-1];
			c = 2;
			ans = max(ans, c);
		}
	}
	
	cout << ans << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
