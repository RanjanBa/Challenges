#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<arr<int, 2>>	pa(n);
	
	for(int i = 0; i < n; i++) cin >> pa[i][0] >> pa[i][1];
	
	sort(pa.begin(), pa.end());
	
	int i = 0, s = 0;
	
	int ans = 0;
	
	while(i < n) {
		s = max(s, pa[i][0]);
		
		int d = pa[i][1] - s;
		int m = d / k + (d % k == 0 ? 0 : 1);
		
		ans += m;
		
		int en = s + m * k;
		
		//cout << "s: " << s << ", en: " << en << ", m: " << m << endl;
		
		i++;
		while(i < n && pa[i][1] < en) {
			i++;
		}
		
		s = en;
	}
	
	cout << ans << endl;
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
