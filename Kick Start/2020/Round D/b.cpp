#include<bits/stdc++.h>
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define EACH(x, a) for (auto& x: a)

void debug() {
}

using namespace std;

/*
// greedy sol
void solve() {
	int k = 0;
	cin >> k;
	vector<int> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	
    int ans = 0, c = 0;
    
    for(int i = 0; i < k - 1; i++) {
		if(a[i] == a[i + 1])
			continue;
			
		if(a[i] < a[i + 1]) {
			c++;
			
			if(c >= 4) {
				ans++;
				c = 0;
			}
		} else {
			c--;
			if(c <= -4) {
				ans++;
				c = 0;
			}
		}
	}
    
    cout << ans << endl;
}
*/

const int mxN = 1e4;

template<class T, class U> void vti(vector<T> &v, U x, size_t n) {
	v=vector<T>(n, x);
}

template<class T, class U> void vti(vector<T> &v, U x, size_t n, size_t m...) {
	v=vector<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

int com(int a, int b) {
	if(a == b)
		return 0;
	
	return a < b ? -1 : 1;
}

void solve() {
	int n, arr[mxN];
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	vector<vector<int>> dp;
	
	vti(dp, 1e9, n, 4);
	
	for(int i = 0; i < 4; i++) {
		dp[0][i] = 0;
	}
	
	for(int i = 1; i < n; i++) {		
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				//int c = 1;
				//if(j < k && arr[i-1] < arr[i])	c = 0;
				//if(j > k && arr[i-1] > arr[i]) c = 0;
				//if(j == k && arr[i-1] == arr[i]) c = 0;
				
				int c = 0;
				
				if(j < k) {
					if(arr[i-1] >= arr[i])
						c = 1;
				} else if(j > k) {
					if(arr[i-1] <= arr[i])
						c = 1;
				} else {
					if(arr[i-1] != arr[i])
						c = 1;
				}
				
				int t = dp[i - 1][j] + c;
				dp[i][k] = min(dp[i][k], t);
			}
		}
	}
	
	int ans = *min_element(dp[n - 1].begin(), dp[n-1].end());
	cout << ans << endl;
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
