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

bool check(int n) {
	set<int> st;
	while(n) {
		int l = n % 10;
		if(st.size()) {
			if(st.find(l) != st.end()) {
				return false;
			}
		}
		
		st.insert(l);
		n /= 10;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int yr;
	
	cin >> yr;
	
	yr++;
	while(true) {
		if(check(yr)) {
			break;
		}
		yr++;
	}
	
	cout << yr << endl;
	
	return 0;
}
