#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<array<int, 2>> v(n);
	for(int i = 0; i < n; i++) {
		int a, b;
		
		cin >> a >> b;
		
		v[i] = {b, a};
	}

	sort(v.begin(), v.end());
	
	int ans = 0, l = 0;
	
	for(int i = 0; i < n; i++) {
		if(v[i][1] >= l) {
			ans++;
			l = v[i][0];
		}
	}
	
	cout << ans << endl;
	
    return 0;
}

