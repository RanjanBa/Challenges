#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1000, mxX = 1e5;

int n, x, v[mxN], p[mxN];

//int dp[mxX + 1][mxN];
//int recursive(int remPrice, int pages = 0, int index = 0) {
	//if(remPrice < 0) {
		//return 0;
	//}
	
	//if(remPrice >= 0 && index >= n) {
		//return pages;
	//}
	
	//if(dp[remPrice][index] != -1) {
		//return dp[remPrice][index] + pages;
	//}
	
	//int ans = recursive(remPrice - v[index], pages + p[index], index + 1);
	
	//ans = max(ans, recursive(remPrice, pages, index + 1));
	
	//dp[remPrice][index] = ans - pages;
	
	//return ans;
//}


// bottom up approach
int dp[mxN][mxX + 1];
int memoization() {
	
	for(int i = 0; i < n; i++) {
		dp[i][0] = 0;
		for(int j = 1; j <= x; j++) {
			if(i > 0) {
				dp[i][j] = max(dp[i - 1][j], j >= v[i] ? dp[i - 1][j - v[i]] + p[i]: 0);
			} else {
				dp[i][j] = max(dp[i][j - 1], j >= v[i] ? p[i] : 0);
			}
		}
	}
	
	return dp[n - 1][x];
}

int main() {	
	cin >> n >> x;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= x; j++) {
			dp[i][j] = -1;
		}
	}
	
	//cout << recursive(x, 0, 0) << endl;
	
	cout << memoization() << endl;
	
	//for(int i = 0; i < n; i++) {
		//for(int j = 0; j <= x; j++) {
			//cout << dp[i][j] << " ";
		//}
		
		//cout << "\n";
	//}
	
    return 0;
}

