#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	int mx = 0;
	ll s = 0;
	for(int i = 0; i < n; i++) {
		int a = 0;
		cin >> a, s+= a;
		
		mx = max(mx, a);
	}
	
	cout << max(s, 2ll * mx) << endl;
	
    return 0;
}

