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

const char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
	string str;
	cin >> str;
	
	int n = str.size();
	transform(str.begin(), str.end(), str.begin(), ::tolower); 
	
	string res = "";
	for(int i = 0; i < n; i++) {
		
		bool flag = false;
		
		for(char ch : vowels) {
			if(ch == str[i]) {
				flag = true;
				break;
			}
		}
		
		if(!flag) {
			res = res + '.' + str[i];
		}
	}
	
	cout << res << endl;
	
	return 0;
}
