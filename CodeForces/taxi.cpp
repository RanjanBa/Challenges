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
	
	vector<int> freq(5);
	
	FOR(i, n) {
		int g;
		cin >> g;
		freq[g]++;
	}
	
	//cout << freq[1] << " " << freq[2] << " " << freq[3] << " " << freq[4] << endl;
	
	if(freq[1] >= freq[3]) {
		freq[1] = freq[1] - freq[3];
	} else {
		freq[1] = 0;
	}
	
	freq[4] += freq[3];
	freq[4] += freq[2] / 2;
	
	if(freq[2] & 1) {
		freq[2] = 1;
	} else {
		freq[2] = 0;
	}
	
	if(freq[2]) {
		freq[2] = 0;
		freq[4]++;
		freq[1] = freq[1] - min(2, freq[1]);
	}
	
	//cout << freq[4] << ", " << freq[1] << "t: " << ceil(freq[1] / (ld)4) << endl;

	freq[4] += ceil(freq[1] / (ld)4);
	
	cout << freq[4] << endl;
	
	return 0;
}
