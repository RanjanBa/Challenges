#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

// solving using bitmask training
int main() {
	int n;
	
	cin >> n;
	
	vector<int> v(n);
	ll s = 0, ans = LLONG_MAX;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i], s+= v[i];
	}
	
	for(int i = 0; i < (1<<n) - 1; i++) {
		ll cs = 0;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) {
				cs += v[j];
			}
		}
		
		ans = min(ans, abs(2 * cs - s));
	}
	
	cout << ans << endl;
}


/*
//ll m = LLONG_MAX;
//vector<int> v1, v2;
//void solve(vector<int> &v, int index) {
	//if(index == (int)v.size()) {
		//ll s1 = 0, s2 = 0;
		//int n = v1.size();
		//for(int i = 0; i < n; i++) {
			//s1 += v1[i];
		//}
		
		//n = v2.size();
		//for(int i = 0; i < n; i++) {
			//s2 += v2[i];
		//}
		
		//s1 = s1 - s2;
		//s1 = abs(s1);
		//m = min(m, s1);
		//return;
	//}
	
	//v1.push(v[index]);
	//solve(v, index+1);
	//v1.pop();
	
	//v2.push(v[index]);
	//solve(v, index+1);
	//v2.pop();
//}

//int main() {
	//int n;
	
	//cin >> n;
	
	//vector<int> v(n);
	//for(int i = 0; i < n; i++) {
		//int w = 0;
		//cin >> w;
		//v[i] = w;
	//}
	
	//if(n == 1) {
		//cout << v[0] << endl;
		//return 0;
	//}
	
	//solve(v, 0);
	
	//cout << m << endl;
	
    //return 0;
//}
*/
