#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n;
	cin >> n;
	
	cout << n << " ";
	while(n > 1) {
		if(n & 1) {
			n *= 3;
			n++;
		}
		else {
			n >>= 1;
		}
		cout << n << " ";
	}
	
	cout << endl;
}

int main() {
    solve();
    return 0;
}

