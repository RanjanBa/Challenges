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


void solve() {
	int n, q;
	
	cin >> n >> q;
	
	string str;
	cin >> str;
	
	while(q--) {
		int l, r;
		
		cin >> l >> r;
		l--, r--;
		
		string sub = "";
		FOR(i, r - l + 1) {
			sub = sub + str[l+i];
		}
		
		bool isGood = true;
		
		if((int)sub.size() >= 2) {
			int s = -1;
			int j = 0;
			
			bool isSub = true;
			
			FOR(i, (int)sub.size()) {
				while(j < n && sub[i] != str[j]) {
					j++;
				}
				
				if(j < n && sub[i] == str[j]) {
					if(i == 0) {
						s = j;
					}
					j++;
				} else {
					isSub = false;
					break;
				}
			}
			
			if(s == -1 || isSub == false) {
				isGood = false;
			} else {
				int len = j - s;
				if(len <= (int)sub.size()) {
					bool f = false;
					
					while(j < n) {
						if(str[j] == sub[sub.size() - 1]) {
							f = true;
							break;
						}
						j++;
					}
					
					if(!f) {
						isGood = false;
					}
				}
			}
			
		} else {
			isGood = false;
		}
		
		if(isGood) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        //cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}

