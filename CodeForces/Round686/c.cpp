#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
#define FORR(i, x) for(int i = x - 1; i >= 0; i--)
#define FORV(v, li) for(auto v : li)

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
	FORV(v, li) {
		cout << v << " ";
	}
	
	cout << endl;
}

template<typename T>
inline void debug(vector<vector<T>> li) {
	FORV(v1, li) {
		FORV(v2, v1) {
			cout << v2 << " ";
		}
		
		cout << endl;
	}
}

const int mxN = 2e5 + 10;

//void solve() {
	//int n;
	//cin >> n;
	
	//vector<int> vec;
	
	//for(int i = 1; i <= n; i++) {
		//int a;
		//cin >> a;
		//if((int)vec.size() == 0 || vec.back() != a) {
			//vec.push_back(a);
		//}
	//}
	
	//cout << "s: " << vec.size() << endl;
	
	//cout << "vec: ";
	//for(int v : vec) {
		//cout << v << " ";
	//}
	//cout << endl;
	
	//map<int, vector<int>> mp;
	
	//for(int i = 0; i < n; i++) {
		//if(mp.find(vec[i]) == mp.end()) {
			//mp[vec[i]].push_back(-1);
		//}
		
		//mp[vec[i]].push_back(i);
	//}
	
	//int res = 1e9;
	//for(auto it : mp) {
		//vector<int> v = it.second;
		//v.push_back(n);
		
		//int cnt = 0;
		//for(int i = 1; i < (int)v.size(); i++) {
			//int d = v[i] - v[i-1];
			
			//if(d > 1) {
				//cnt++;
			//}
		//}
		//res = min(res, cnt);
	//}
	
	//cout << res << endl;
//}

void solve() {
	int n;
	cin >> n;
	
	vector<int> vec;
	
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if((int)vec.size() == 0 || vec.back() != a) {
			vec.push_back(a);
		}
	}
	
	//cout << "s: " << vec.size() << endl;
	
	map<int, int> mp;
	int res = 1e9;
	
	if(vec.size() >= 2) {
		for(int i = 0; i < (int)vec.size(); i++) {
			if(i == 0) {
				mp[vec[i]] = 1;
			} else if(i == (int)vec.size() - 1) {
				if(mp.find(vec[i]) == mp.end()) {
					mp[vec[i]] = 1;
				}
			} else {
				if(mp.find(vec[i]) != mp.end()) {
					mp[vec[i]] += 1;
				} else {
					mp[vec[i]] = 2;
				}
			}
		}
			
		for(auto it : mp) {
			res = min(res, it.second);
		}
	} else {
		res = 0;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        //cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

