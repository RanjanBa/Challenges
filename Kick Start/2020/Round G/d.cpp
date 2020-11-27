#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

int n = 0;
ll vec[5000];

//ll tSum = 0, c = 0;

//void dfs(vector<ll> vec, ll sum = 0) {
	//if(vec.size() == 1) {
		//tSum += sum;
		//c++;
		//return;
	//}
	
	//for(int i = 0; i < (int)vec.size()-1; i++) {
		//vector<ll> newVec = vec;
		//ll t = vec[i] + vec[i+1];
		
		//newVec[i] = t;
		//newVec.erase(newVec.begin()+i+1);
		
		//dfs(newVec, sum + t);
	//}
//}

//void solve() {
	//cin >> n;
	
	//vector<ll> vec(n);
	
	//for(int i = 0; i < n; i++) {
		//cin >> vec[i];
	//}
	
	//dfs(vec);
	
	//ld res = tSum / (ld)c;
	//cout << fixed << setprecision(9) << res << endl;
	//tSum = 0, c = 0;
//}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	ld ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		for(int j = 0; j <= i; j++) {
			ans += (ld)vec[j] / (ld)(i - j + 1);
		}
		
		for(int j = i + 1; j < n; j++) {
			ans += (ld)vec[j] / (ld)(j - i);
		}
	}
	
	cout << fixed << setprecision(9) << ans << endl;
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
