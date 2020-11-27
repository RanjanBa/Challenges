#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n, a, b;
	
	cin >> n >> a >> b;
	
	vector<ll> prefS(n + 1);
	prefS[0] = 0;
	for(int i = 1; i <= n; i++) {
		int t = 0;
		cin >> t;
		prefS[i] = prefS[i - 1] + t;
	}
	
	set<ar<ll, 2>> s;
	ll ans = LLONG_MIN;
	
	for(int i = 0; i <= n; i++) {
		if(i >= a) {
			s.insert({prefS[i-a], i - a});
		}
		
		if(s.size()) {
			ans = max(ans, prefS[i] - (*s.begin())[0]);
		}
		
		if(i >= b) {
			s.erase({prefS[i - b], i - b});
		}
	}
	
	cout << ans << endl;
	
	return 0;
}


// time limit exceeded
//int main() {
	//int n, a, b;
	
	//cin >> n >> a >> b;
	
	//vector<ll> prefS(n + 1);
	//prefS[0] = 0;
	//for(int i = 1; i <= n; i++) {
		//int t = 0;
		//cin >> t;
		//prefS[i] = prefS[i - 1] + t;
	//}
	
	//ll ans = LLONG_MIN;
	//for(int i = a; i <= b; i++) {
		//for(int j = i; j <= n; j++) {
			//ll s = prefS[j] - prefS[j - i];
			//ans = max(ans, s);
		//}
	//}
	
	//cout << ans << endl;
	
    //return 0;
//}

