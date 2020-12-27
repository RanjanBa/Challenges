#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

int main() {
	string s;
	
	cin >> s;
	
	sort(s.begin(), s.end());
	
	vector<string> ans;
	
	do {
		ans.pb(s);
	} while(next_permutation(s.begin(), s.end()));
		
	cout << ans.size() << endl;
	
	for(string st: ans) {
		cout << st << endl;
	}
	
    return 0;
}

