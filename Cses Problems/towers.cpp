#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v;
	
	int a = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> a;
		
		int p = upper_bound(v.begin(), v.end(), a) - v.begin();
		
		if(p < v.size()) {
			v[p] = a;
		} else {
			v.push(a);
		}
	}
	
	cout << v.size() << endl;
	
    return 0;
}

