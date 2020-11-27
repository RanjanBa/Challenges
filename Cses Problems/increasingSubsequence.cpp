#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 2 * 1e5;

int n, a[mxN];

//int recursive(int index, int len) {
	//if(index >= n - 1) {
		//return len;
	//}
	
	//int ans = 0;
	//for(int i = index + 1; i < n; i++) {
		//if(a[i] > a[index])
			//ans = max(ans, recursive(i, len + 1));
	//}
	
	//return ans;
//}

int dp[mxN];

int main() {
	cin >> n;
	
	//for(int i = 0; i < n; i++) {
		//cin >> a[i];
	//}
	
	vector<int> v;
	int t = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> t;
		
		int p = lower_bound(v.begin(), v.end(), t) - v.begin();
		
		if(p < (int)v.size()) {
			v[p] = t;
		} else {
			v.push(t);
		}
	}
	
	cout << v.size() << endl;
	
	//for(int i: v) {
		//cout << i << " ";
	//}
	
	//cout << endl;
	
	
	//int ans = 0;
	
	//for(int i = 0; i < n; i++) {
		//ans = max(ans, recursive(i, 1));
	//}
	//cout << ans << endl;
	
	//for(int i = 0; i < n; i++) {
		//dp[i] = 1;
	//}
	
	//for(int i = 1; i < n; i++) {
		//for(int j = 0; j < i; j++) {
			//if(a[i] > a[j]) {
				//dp[i] = max(dp[i], dp[j] + 1);
			//}
		//}
	//}
	
	//cout << *max_element(dp, dp + n) << endl;
	
    return 0;
}

