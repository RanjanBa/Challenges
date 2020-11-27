#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int secondSol() {
	int n, a;
	
	cin >> n;
	
	ll ans = -1e18, msf = -1e18;
	
	for(int i = 0; i < n; i++) {
		cin >> a;
		
		msf = max((ll)a, msf + a);
		
		ans = max(ans, msf);
	}
	
	cout << ans << endl;
	
	return 0;
}

int main() {
	secondSol();
	//int n, a;
	
	//cin >> n;
	
	//ll s = 0, ans = 0, ans2 = INT_MIN;
	//bool allNeg = true;
	
	//for(int i = 0; i < n; i++) {
		//cin >> a, s+= a;
		
		//if(a >= 0) {
			//allNeg = false;
		//}
		
		//if(allNeg) {
			//ans2 = max(ans2, (ll)a);
		//}

		//if(s < 0) {
			//s = 0;
		//}
		
		//ans = max(ans, s);
	//}
	
	//cout << (allNeg ? ans2 : ans) << endl;
	
    //return 0;
}

