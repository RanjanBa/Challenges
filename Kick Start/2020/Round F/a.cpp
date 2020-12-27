#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	
	vector<int> v(n);
	//queue<arr<int, 2>> qu;
	
	map<int, vector<int>> mp;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		
		int d = v[i] % x == 0 ? v[i] / x - 1 : v[i] / x;
		
		if(mp.find(d) != mp.end()) {
			mp[d].push_back(i);
		} else {
			mp[d] = {i};
		}
	}
	
	vector<int> res;
	
	for(auto it : mp) {
		vector<int> vec = it.second;
		
		for(int i : vec) res.push_back(i+1);
	}
	
	//while(qu.size()) {
		//arr<int, 2> ar = qu.front();
		//qu.pop();
		
		//int i = ar[0], s = ar[1];
		//if(s + x < v[i]) {
			//qu.push({i, s + x});
		//} else {
			//res.push_back(i+1);
		//}
	//}
	
	for(int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
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
