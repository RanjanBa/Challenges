#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

const int mxN = 2 * 1e5;

int n;
ar<int, 3> a[mxN];

//int recursion(int index, int end, ll reward) {
	//if(a[index][0] <= end) {
		//return reward;
	//}
	//end = a[index][1];
	//reward += a[index][2];
	//cout << "index: " <<  index << ", rew: " << reward << ", end: " << end << endl;
	//int mx = reward;
	//for(int i = index + 1; i < n; i++) {
		//mx = max(mx,recursion(i, end, reward));
	//}
	
	//return mx;
//}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i][1] >> a[i][0] >> a[i][2];
	}
	
	sort(a, a + n);
	
	//int ans = 0;
	//for(int i = 0; i < n; i++) {
		//cout << "Test: " << i << endl;
		//ans = max(ans, recursion(i, 0, 0));
	//}
	
	//cout << ans << endl;

	set<ar<ll, 2>> dp;
	dp.insert({0, 0});
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		auto it = dp.lower_bound({a[i][1]});
		--it;
		ans = max(ans, ((*it)[1] + a[i][2]));
		dp.insert({a[i][0], ans});
	}
	
	cout << ans << endl;
	
    return 0;
}

