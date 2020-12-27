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

const int mxN = 100;

bool com(const int a, const int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> odd;

	int ev_sum = 0;
	FOR(i, n) {
		int a;
		cin >> a;
		
		if((a&1) == 0) {
			ev_sum += a;
		} else {
			odd.phb(a);
		}
	}
	
	sort(odd.begin(), odd.end(), com);
	int res = 0, si = odd.size();
	if(si) {
		int od_sum = 0;
		FOR(i, (int)odd.size()) {
			od_sum += odd[i];
		}
		
		if((si&1) == 0) {
			od_sum -= odd[si-1];
		}
		
		res = ev_sum + od_sum;
	}
	
	cout << res << endl;
	
	return 0;
}
