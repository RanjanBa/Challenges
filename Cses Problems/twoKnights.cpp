#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		int a = i * i;
		ll ans = (ll)a * (a - 1) / 2;
		
		if(n >= 2) {
			ans -= (ll)4 * (i - 1) * (i - 2);
		}
		
		cout << ans << endl;
	}
	
    return 0;
}

