#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, p;
	
	cin >> n >> p;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int diff = 0;
	for(int i = 0; i < p; i++) {
		diff += a[p - 1] - a[i];
	}
	
	int minDiff = diff;
	for(int i = p, j = 0; i < n; i++, j++) {
		diff -= (a[i - 1] - a[j]);
		diff += (p - 1) * (a[i] - a[i-1]);
		minDiff = min(minDiff, diff);
	}
	
	cout << minDiff << endl;
}

int main(int argc, const char* argv[]) {
    int t;
    
    cin >> t;
    
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
