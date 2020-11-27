#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e3;

int n, q, a[mxN+1][mxN+1];

int main() {
	cin >> n >> q;
	
	memset(a, 0, sizeof(a));
	
	for(int i = 0; i < n; i++) {
		string str;
		
		cin >> str;
		
		for(int j = 0; j < n; j++) {
			if(str[j] == '*') {
				a[i+1][j+1] = 1;
			}
			
			a[i+1][j+1] += a[i+1][j];
		}
	}
	
	for(int j = 1; j <= n; j++) {
		for(int i = 1; i <= n; i++) {
			a[i][j] += a[i-1][j];
		}
	}
	
	while(q--) {
		int y1, x1, y2, x2;	
		
		cin >> y1 >> x1 >> y2 >> x2;
		
		y1--, x1--;
		int res = a[y2][x2] - a[y1][x2] - a[y2][x1] + a[y1][x1];
		
		cout << res << endl;
	}
	
    return 0;
}

