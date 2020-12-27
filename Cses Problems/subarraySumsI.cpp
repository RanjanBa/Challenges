#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n, x;
	
	cin >> n >> x;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int s = 0, ans = 0;
	int i = 0, j = 0;
	while(i <= j && j < n) {
		if(s + v[j] > x) {
			s -= v[i];
			i++;
		} else if(s + v[j] < x) {
			s += v[j];
			j++;
		} else {
			ans++;
			s -= v[i];
			s += v[j];
			i++;
			j++;
		}
	}
	
	cout << ans << endl;
	
    return 0;
}

