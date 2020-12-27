#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 100, mxX = 1000;

int n, a[mxN];

/*
int ans[mxN * mxX + 1];
void recursion(int index, int sum) {
	if(index >= n) {
		return;
	}
	
	recursion(index + 1, sum);
	
	ans[sum + a[index]] = 1;
	recursion(index + 1, sum + a[index]);
}
*/

int dp[mxN * mxX + 1];
void memoization() {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
	}
	
	dp[0] = 1;
	for(int j = 0; j < n; j++) {
		for(int i = sum; i; i--) {
			if(i >= a[j])
				dp[i] |= dp[i-a[j]];
		}
		
		//for(int i = 1; i <= sum; i++) {
			//cout << dp[i] << " ";
		//}
		
		//cout << endl;
	}
	
	vector<int> ans;
	
	for(int i = 1; i <= sum; i++) {
		if(dp[i])
			ans.push(i);
	}
	
	cout << ans.size() << endl;
	for(int i: ans) {
		cout << i << " ";
	}
	
	cout << endl;
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	/*
	recursion(0, 0);
	vector<int> v;
	for(int i = 1; i <= mxN * mxX; i++) {
		if(ans[i] == 1) {
			v.push(i);
		}
	}
	
	cout << v.size() << endl;
	for(int i: v) {
		cout << i << " ";
	}
	
	cout << endl;
	*/
    
    memoization();
    
    return 0;
}
