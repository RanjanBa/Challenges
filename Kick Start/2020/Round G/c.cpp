#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

int w, n;

//void solve() {
	//cin >> w >> n;;
	
	//vector<int> vec(w);
	
	//for(int i = 0; i < w; i++) {
		//cin >> vec[i];
	//}
	
	//ll res = 1e18;
	//for(int i = 1; i <= n; i++) {
		//ll localMin = 0;
		//for(int j = 0; j < w; j++) {
			//int t = 0;
			//if(i >= vec[j]) {
				//t = min(i - vec[j], n - i + vec[j]);
			//} else {
				//t = min(vec[j]-i, n - vec[j] + i);
			//}
			//localMin += t;
		//}
		//res = min(res, localMin);
	//}
	
	//cout << res << endl;
//}

void solve1() {
	cin >> w >> n;;
	
	vector<int> vec(w);
	
	for(int i = 0; i < w; i++) {
		cin >> vec[i];
	}
	
	ll res = 1e18;
	for(int i = 0; i < w; i++) {
		ll localMin = 0;
		for(int j = 0; j < w; j++) {
			int t = 0;
			if(vec[i] >= vec[j]) {
				t = min(vec[i] - vec[j], n - vec[i] + vec[j]);
			} else {
				t = min(vec[j]-vec[i], n - vec[j] + vec[i]);
			}
			localMin += t;
		}
		res = min(res, localMin);
	}
	
	cout << res << endl;
}

int searchRight(vector<ll>& vec, ll x) {
	int l = x, h = w-1;
	int res = w;
	while(l <= h) {
		ll m = l + (h - l) / 2;
		int dl = vec[m] - vec[x];
		int dr = n - vec[m] + vec[x];
		if(dr < dl) {
			h = m - 1;
			res = m;
		} else {
			l = m + 1;
		}
	}
	
	return res;
}

int searchLeft(vector<ll>& vec, ll x) {
	int l = 0, h = x;
	int res = -1;
	while(l <= h) {
		ll m = l + (h - l) / 2;
		int dr = vec[x] - vec[m];
		int dl = n + vec[m] - vec[x];
		if(dl < dr) {
			l = m + 1;
			res = m;
		} else {
			h = m - 1;
		}
	}
	
	return res;
}

void solve() {
	cin >> w >> n;;
	
	vector<ll> vec(w);
	
	for(int i = 0; i < w; i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	vector<ll> prefix(w), suffix(w);
	
	//cout << endl;
	for(int i = 0; i < w; i++) {
		//cout << vec[i] << " ";
		
		prefix[i] = vec[i];
		
		if(i) {
			prefix[i] += prefix[i-1];
		}
	}
	
	//cout << endl;
	
	for(int i = w-1; i >= 0; i--) {
		suffix[i] = n - vec[i];
		
		if(i < w-1) {
			suffix[i] += suffix[i+1];
		}
	}
	
	ll res = 1e18;
	
	for(int i = 0; i < w; i++) {
		int l = searchLeft(vec, i);
		int r = searchRight(vec, i);
		
		//cout << i << " : " << l << ", " << r;
		
		ll ls = (i-l) * vec[i] - prefix[i];
		if(l >= 0) {
			ls += prefix[l];
			ls += prefix[l] + (l + 1) * (n - vec[i]);
		}
		
		//cout << ", ls : " << ls;
		
		ll rs = prefix[r-1] - prefix[i] - (r - i - 1) * vec[i];
		if(r < w)
			rs += suffix[r] + (w-r) * vec[i];
		//cout << ", rs : " << rs;
		
		res = min(res, ls + rs);
		
		//cout << ", ts: " << (ls + rs) << endl;
	}
	
	cout << res << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
        
        //cout << "Case #" << t << ": ";
        //solve1();
    }
    
    return 0;
}
