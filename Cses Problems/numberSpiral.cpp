#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int t;
	
	cin >> t;
	
	while(t--) {
		ll y, x;
		
		cin >> y >> x;
		
		ll ans = 0;
		
		if(y == x) {
			ans = y * y - (y - 1);
		} else if(y > x){
			ll sq = y * y - (y - 1);
			
			if(y & 1) {
				ans = sq - (y - x);
			} else {
				ans = sq + (y - x);
			}
		} else {
			ll sq = x * x - (x - 1);
			
			if(x & 1) {
				ans = sq + (x - y	);
			} else {
				ans = sq - (x - y);
			}
		}
		
		cout << ans << endl;
	}
	
    return 0;
}

