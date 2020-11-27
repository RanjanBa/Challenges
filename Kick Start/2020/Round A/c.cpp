#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	
    cin >> n >> k;
    
    vector<int> diff(n-1);
    
	int prev = 0, mx = 0;
	cin >> prev;
	
    for(int i = 0; i < n-1; i++) {
		int a = 0;
		cin >> a;
		diff[i] = a - prev;
		mx = max(mx, diff[i]);
		
		prev = a;
	}
	
	int low = 1, high = mx;
	int ans = mx;
	while(low <= high) {
		int mid = low + (high-low) / 2;
		
		int k_sum = 0;
		
		for(int i = 0; i < n-1; i++) {
			if(diff[i] >= mid) {
				k_sum += ceil(diff[i] / (double)mid) - 1;
			}
		}
		
		if(k_sum > k) {
			low = mid + 1;
		} else {
			ans = mid;
			high = mid - 1;
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
