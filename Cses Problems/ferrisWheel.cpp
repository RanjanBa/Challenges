#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n, x;
	
	cin >> n >> x;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	int l = 0, h = n - 1, ans = 0;

	while(l <= h) {
		if(v[h] + v[l] <= x) {
			h--;
			l++;
			ans++;
			continue;
		}
		
		if(v[h] <= x) {
			h--;
			ans++;
			continue;
		}
	}
	
	cout << ans << endl;
	
    return 0;
}

