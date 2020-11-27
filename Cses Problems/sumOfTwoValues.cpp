#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n, x, a;
	
	cin >> n >> x;
	
	map<int, int> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> a;
		if(m.find(a) != m.end()) {
			cout << m[a] << " " << i << endl;
			return 0;
		}
		
		m.insert({x - a, i});
	}
	
	cout << "IMPOSSIBLE" << endl;
	
    return 0;
}

