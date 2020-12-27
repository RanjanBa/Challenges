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

vector<int> luckyDigits = {4, 7};
vector<int> luckyNums;

void generateLucky(int digitsCnt, int n) {
	if(digitsCnt < 0) return;
	if(digitsCnt == 0) {
		if(n != 0)
			luckyNums.push_back(n);
		return;
	}
	
	FORV(v, luckyDigits) {
		int t  = n * 10;
		t += v;
		generateLucky(digitsCnt - 1, t);
	}
	
	if(n != 0) {
		luckyNums.phb(n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	generateLucky(3, 0);
	
	int n;
	cin >> n;
	
	FORV(v, luckyNums) {
		if(n % v == 0) {
			cout << "YES" << endl;
			return 0;
		} 
	}
	
	cout << "NO" << endl;
	
	return 0;
}
