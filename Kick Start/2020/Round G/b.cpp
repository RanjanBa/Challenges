#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

int n;

bool can(int i, int j) {
	return i >= 0 && j >=0 && i < n && j < n;
}

void solve() {
	cin >> n;
	
	int mat[n][n];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	ll res = 0;
	for(int k = 0; k < n; k++) {
		ll localMx = 0;
		int i = 0, j = k;
		while(true) {
			if(!can(i, j)) {
				break;
			}
			
			localMx += mat[i][j];
			i++;
			j++;
		}
		
		//cout << "loc: " << localMx << endl;
		
		res = max(res, localMx);
	}
	
	for(int k = 1; k < n; k++) {
		ll localMx = 0;
		int i = k, j = 0;
		while(true) {
			if(!can(i, j)) {
				break;
			}
			
			localMx += mat[i][j];
			i++;
			j++;
		}
		
		//cout << "loc: " << localMx << endl;
		
		res = max(res, localMx);
	}
	
	cout << res << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
