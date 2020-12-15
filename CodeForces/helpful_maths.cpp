#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
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
	int nums[4];
	memset(nums, 0,  sizeof(nums));
	FORV(ch, str) {
		if(ch == '+') {
			continue;
		} else {
			int a = ch - '0';
			nums[a]++;
		}
	}
	
	vector<int> res;
	FOR(i, 4) {
		if(i == 0) continue;
		
		while(nums[i]) {
			res.push_back(i);
			nums[i]--;
		}
	}
	
	FOR(i, (int)res.size() - 1) {
		cout << res[i] << "+";
	}
	
	cout << res.back() << endl;
	
	return 0;
}
