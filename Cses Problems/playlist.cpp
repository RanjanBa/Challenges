#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	map<int, int> m;
	int ans = 0;
	
	for(int i = 0, j = 0; i < n; i++) {
		while(j < n && m[v[j]] < 1) {
			m[v[j]]++;
			j++;
		}
		
		ans = max(j - i, ans);
		m[v[i]]--; 
	}
	
	cout << ans << endl;
	
    return 0;
}

