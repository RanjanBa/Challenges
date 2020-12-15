#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
#define FORS(i, s, x) for(int i = s; i < x; i++)
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

// ------ main function ------

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> str;
	
	int n = str.size();
	
	int cnt = 0;
	FORV(ch, str) {
		if('A' <= ch && ch <= 'Z') {
			cnt++;
		}
	}
	
	if(2 * cnt > n) {
		transform(str.begin(), str.end(), str.begin(), ::toupper);
	} else {
		transform(str.begin(), str.end(), str.begin(), ::tolower);
	}
	
	cout << str << endl;
	
	return 0;
}
