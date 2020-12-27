#include<bits/stdc++.h>

using namespace std;

void dbgV(vector<int> v) {
	for(int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

/*
void test {
	while(q--) {
		int s, k;
		cin >> s >> k;
		
		int l = s - 1, r = s;
		int ans = s;
		while(--k) {
			if(r >= n || (l >= 1 && doors[l] < doors[r])) {
				l--;
				ans = l + 1;
			} else {
				r++;
				ans = r;
			}
		}
		cout << ans << " ";
	}
	 
	cout << endl;
}
*/

void solve() {
	int n, q;
	
	cin >> n >> q;
	
	vector<int> doors(n);
	
	for(int i = 0; i < n - 1; i++) {
		cin >> doors[i];
	}
	
	vector<int> ld(n-1), rd(n-1);
	
	stack<int> st;
	for(int i = 0; i < n - 1; i ++) {
		while(!st.empty() && st.top() < doors[i]) {
			st.pop();
		}
		
		if(!st.empty())
			ld[i] = st.top();
		else
			ld[i] = -1;
		
		st.push(doors[i]);
	}

	while(!st.empty())
		st.pop();
		
	for(int i = n - 2; ~i; i--) {
		while(!st.empty() && st.top() < doors[i]) {
			st.pop();
		}
		
		if(!st.empty())
			rd[i] = st.top();
		else
			rd[i] = -1;
		
		st.push(doors[i]);
	}
	
	while(q--) {
		int s, k;
		cin >> s >> k;
	}
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
