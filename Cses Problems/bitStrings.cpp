#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

#define MOD 1000000007;

using namespace std;

ll power(int b, int p) {
	if(p == 0) {
		return 1;
	}
	
	if(p == 1) {
		return b;
	}
	
	ll a = power(b, p / 2);
	
	a = (a * a) % MOD;
	
	if(p & 1) {
		a *= b;
	}
	
	return a % MOD;
}

int main() {
	int n;
	
	cin >> n;
	
	cout << power(2, n) << endl;
	
    return 0;
}

