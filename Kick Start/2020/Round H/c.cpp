#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()

using namespace std;

const int INF = 1e9;
const int mxN = 1e5;

int n;
arr<ll, 2> pos[mxN];

void solve() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> pos[i][1] >> pos[i][0];
	}
	
	sort(pos, pos + n);
	
	ll res = 0;
	int m = n >> 1;
	
	for(int i = 0; i < n; i++) {
		res += abs(pos[i][0] - pos[m][0]);
	}
	
	for(int i = 0; i < n; i++) {
		swap(pos[i][0], pos[i][1]);
	}
	
	//cout << "y: " << res << endl;
	
	sort(pos, pos + n);
	
	for(int i = 0; i < n; i++) {
		if(i <= m) {
			res += abs(pos[m][0] - pos[i][0] - (m - i));
		} else {
			res += abs(pos[i][0] - pos[m][0] - (i - m));
		}
	}
	
	cout << res << endl;
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
