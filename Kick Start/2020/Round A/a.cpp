#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

void solve() {
	int n, b;
	
    cin >> n >> b;
    
    vector<int> vec(n);

    for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	sort(all(vec));
	
	int sum = 0;
	int ans = 0;
	while(ans < n && sum + vec[ans] <= b) {
		sum += vec[ans];
		ans++;
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
