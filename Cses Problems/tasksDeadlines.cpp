#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n;

	cin >> n;

	vector<ar<int, 2>> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	sort(v.begin(), v.end());

	ll r = 0, s = 0;
	for(int i = 0; i < n; i++) {
		s += v[i][0];
		r += (v[i][1] - s);
	}

	cout << r << endl;

    return 0;
}

