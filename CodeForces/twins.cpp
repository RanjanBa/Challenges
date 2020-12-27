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
	
	int n;
	cin >> n;
	
	vector<int> vec(n);
	
	FOR(i, n) cin >> vec[i];
	
	sort(vec.begin(), vec.end());
	
	int sum = accumulate(vec.begin(), vec.end(), 0);
	
	int cs = 0;
	int cnt = 0;
	FORR(i, n) {
		cs += vec[i];
		cnt++;
		
		if(2 * cs > sum) {
			break;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
