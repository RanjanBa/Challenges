#include<bits/stdc++.h>
#define ll long long
#define ar array
#define phb push_back
#define ppb pop_back
using namespace std;

int n, a, b, c;
bool check(vector<int> &v) {
	int andre = 0;
	int mx = 0;
	for(int i = 0; i < (int)v.size(); i++) {
		if(v[i] >= mx) {
			andre++;
			mx = max(v[i], mx);
		}
	}
	
	int sule = 0;
	mx = 0;
	for(int i = n-1; i >= 0; i--) {
		if(v[i] >= mx) {
			sule++;
			mx = max(v[i], mx);
		}
	}
	
	int both = 0;
	mx = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] > mx) {
			both = 1;
			mx = v[i];
		} else if(v[i] == mx) {
			both++;
		}
	}
	
	bool t = andre == a && sule == b && both == c;
	
	return t;
}

bool buildArr(vector<int> &v, int index) {
	if(index == n) {
		int t = check(v);
		return t;
	}
	
	for(int i = n; i >= 1; i--) {
		v[index] = i;
		if(buildArr(v, index+1)) return true;
	}
	
	return false;
}

void optimizeSolve() {
	vector<int> v;
	if(n == 1) {
		if(a + b - c == 1) {
			v.phb(n);
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	} else if(n == 2) {
		if((a == 1 && b == 2 && c == 1) ||(a == 2 && b == 1 && c == 1) ||(a == 2 && b == 2 && c == 2)) {
			v.phb(1);
			v.phb(2);
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	} else {
		if(a + b - c <= n && c <= a && c <= b && a + b - c != 1) {
			for(int i = 1; i <= a-c; i++) {
				v.phb(n-i);
			}
			
			if(a - c != 0) {
				reverse(v.begin(), v.end());
				for(int i = 1; i <= n - (a + b - c); i++) {
					v.phb(1);
				}
			} else {
				v.phb(n);
			}
			
			v.phb(n);
			
			for(int i = 1; i < c; i++) {
				v.phb(n);
			}
			
			if(a - c == 0) {
				for(int i = 1; i <= n - (a + b - c); i++) {
					v.phb(1);
				}
			}
			
			for(int i = 1; i <= b - c; i++) {
				v.phb(n-i);
			}
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	
	for(int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " ";
	}
	
	cout << endl;
}

void solve() {
	cin >> n >> a >> b >> c;
	
	optimizeSolve();
	
	//vector<int> v(n);
	//bool t = buildArr(v, 0);
	//if(t == true) {
		//for(int i = 0; i < n; i++) {
			//cout << v[i] << " ";
		//}
		//cout << endl;	
	//} else {
		//cout << "IMPOSSIBLE" << endl;
	//}
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
