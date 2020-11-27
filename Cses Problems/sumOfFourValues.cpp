#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n, x;
	
	cin >> n >> x;
	
	vector<ar<int, 2>> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i][0];
		v[i][1] = i + 1;
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ll need = x - v[i][0] - v[j][0];
			
			int k = j + 1, l = n - 1;
			while(k < l) {
				if(v[k][0] + v[l][0] == need) {
					vector<int> ans = {v[i][1], v[j][1], v[k][1], v[l][1]};
					sort(ans.begin(), ans.end());
					
					for(int t : ans) {
						cout << t << " ";
					}
					cout << endl;
					return 0;
				} else if(v[k][0] + v[l][0] < need) {
					k++;
				} else {
					l--;
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
	
    return 0;
}

