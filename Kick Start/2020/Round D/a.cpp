#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
    int ans = 0, mx = -1;

    for(int i = 0; i < n; i++) {
		if(mx < a[i] && (i == n - 1 || a[i] > a[i + 1])) {
			ans++;
		}
		mx = max(mx, a[i]);
	}
    cout << ans << "\n";
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
