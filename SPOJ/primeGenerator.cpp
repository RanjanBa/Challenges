#include<bits/stdc++.h>

using namespace std;
const int mxN = 1e9;

int main() {
	int t;
	
	cin >> t;
	
	while(t--) {
		int m, n;
		cin >> m >> n;
		
		for(int i = m; i <= n; i++) {
			if(i == 2) {
				cout << i << endl;
				continue;
			}
			
			if(i == 1 || i == 0 || i % 2 == 0) continue;
			
			bool flag = true;
			for(int j = 2; j * j <= i; j++) {
				if(i % j == 0) {
					flag = false;
					break;
				}
			}
			
			if(flag) cout << i << endl;
		}
		
		cout << endl;
	}
	
	return 0;
}
