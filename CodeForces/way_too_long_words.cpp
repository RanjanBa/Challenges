#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
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
 
// ------ main function ------
 
int main() {
	int n;
	
	cin >> n;
	
	string str, res;
	FOR(i, n) {
		cin >> str;
		res = str;
		
		int s = str.size();
		if(s > 10) {
			res = str[0] + to_string(s-2) + str[s-1];
		}
		
		cout << res << endl;
	}
	
	return 0;
}
