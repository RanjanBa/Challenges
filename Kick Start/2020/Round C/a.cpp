#include<bits/stdc++.h>

using namespace std;

void solve() {
	int N , K;
	
    cin >> N >> K;
    
    int cur = K;
    int ans = 0;
    
    for(int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		
		if(cur == a) {
			cur--;
		}
		else {
			if(a == K) {
				cur = K - 1;
			}
			else {
				cur = K;
			}
		}
		
		if(cur == 0) {
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
