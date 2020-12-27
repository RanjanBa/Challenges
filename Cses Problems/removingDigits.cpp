#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e6;

// overlapping
int recursive(int n, int c = 0) {
	if(n == 0) {
		return c;
	}
	
	int t = n;
	int ans = 1e9;
	while(t) {
		int r = t % 10;
		if(r > 0 && n >= r) {
			ans = min(ans, recursive(n - r, c + 1));
		}
		
		t /= 10;
	}
	
	return ans;
}


// top bottom approach
int dp[mxN + 1];
int memoization(int n, int c = 0) {
	if(n == 0) {
		return c;
	}
	
	if(dp[n] != -1) {
		return dp[n] + c;
	}
	
	int t = n;
	int ans = 1e9;
	while(t) {
		int r = t % 10;
		if(r > 0 && n >= r) {
			ans = min(ans, memoization(n - r, c + 1));
		}
		
		t /= 10;
	}
	if(ans < 1e9) {
		dp[n] = ans - c;
	} else {
		dp[n] = 1e9;
	}
	
	return ans;
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	
	//vector<int> dp(n + 1, 1e9);
	//dp[0] = 0;
	//for(int i = 1; i <= n; i++) {
		//int t = i;
		//while(t) {
			//int r = t % 10;
			//if(i >= r) {
				//dp[i] = min(dp[i], dp[i - r] + 1);
			//}
			
			//t = t / 10;
		//}
	//}
	
	//cout << dp[n] << endl;
	
	//cout << recursive(n) << endl;
	cout << memoization(n) << endl;
	
    return 0;
}

