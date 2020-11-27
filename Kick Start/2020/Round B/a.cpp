#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<long long> vec(n);
	
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	int ans = 0;
	
	for(int i = 1; i < n - 1; i++) {
		if(vec[i-1] < vec[i] && vec[i] > vec[i+1]) {
			ans++;
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
