#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e6+1;

int a[mxN+1][7];

//int overlaping(int rs, int cs = 0) {
	//if(rs < cs) {
		//return 0;
	//}
	//else if(rs == cs) {
		//return 1;
	//}
	
	//int ans = 0;
	//for(int i = 1; i <= 6; i++) {
		//ans = (ans + overlaping(rs, cs + i)) % MOD;
	//}
	
	//return ans;
//}

int memoization(int rs, int cs = 0) {
	if(rs < cs) {
		return 0;
	}
	else if(rs == cs) {
		return 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= 6; i++) {
		if(a[cs + i][i] != -1) {
			ans = (ans + a[cs + i][i]) % MOD;
		} else {
			int t = memoization(rs, cs + i);
			t %= MOD;
			a[cs + i][i] = t;
			ans = (ans + t) % MOD;
		}
		
	}
	
	return ans;
}

int main() {
	int n;
	
	cin >> n;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= 6; j++) {
			a[i][j] = -1;
		}
	}
	
	cout << memoization(n) << endl; 
	
    return 0;
}

	
