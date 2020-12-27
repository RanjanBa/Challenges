#include<bits/stdc++.h>

using namespace std;

const int maxA = 1e5;

//unordered_set<int> powers;

//void build() {
	//for(int i = 0; i * i <= 100 * 100000; i++) {
		//powers.insert(i * i);
	//}
//}

//void solve() {
	//int n;
	//cin >> n;
	//vector<int> A(n);
	
	//for(int i = 0; i < n; i++) {
		//cin >> A[i];
	//}
	
	//long long ans = 0;
	
	//for(int i = 0; i < n; i++) {
		//int sum = 0;
		//for(int j = i; j < n; j++) {
		    //sum += A[j];
		    
		    //if(powers.find(sum) != powers.end()) {
				//ans++;
			//}
		//}
	//}
	
	//cout << ans << endl;
//}

void solve() {
	int n = 0;
	
	cin >> n;
	
	int offset = 0;
	vector<int> A(n);
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		offset += abs(A[i]);
	}
	vector<int> c(2 * offset + 1);
	int prefix = 0;
	long long ans = 0;
	c[offset] = 1;
	for(int i = 0; i < n; i++) {
		prefix += A[i];
		for(int j = 0; j * j <= offset + prefix; j++) {
			ans += c[offset + prefix - j * j];
		}
		
		c[offset + prefix]++;
	}
	
	cout << ans << endl;
}

int main() {
    int T;
    
    cin >> T;
    //build();
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

