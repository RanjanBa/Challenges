#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	while(n--) {
		int a , b;
		cin >> a >> b;
		
		int mx = max(a, b);
		int mi = min(a, b);
		
		a += b;
		
		if(a % 3 == 0 && 2 * mi >= mx) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
    return 0;
}

