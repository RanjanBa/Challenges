#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	ll t = 5;
	
	int ans = 0;
	while(t <= n) {
		ans += (n / t);
		t *= 5;
	}
	
	cout << ans << endl;
	
    return 0;
}

