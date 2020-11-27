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
	
	int n;
	cin >> n;
	
	//vector<int> vec(n);
	
	stack<int> st;
	int nest = 0, fin = -1, mxlen = 0, fim = -1;
	
	int cnt = 0;
	FOR(i, n) {
		int b;
		cin >> b;
		
		if(b == 1) {
			cnt++;
			if(cnt > nest) {
				nest = cnt;
				fin = i  + 1;
			}
			st.push(i);
		} else {
			cnt--;
			assert(st.size() != 0);
			
			int len = i - st.top() + 1;
			if(len > mxlen) {
				mxlen = len;
				fim = st.top() + 1;
			}
			
			st.pop();
		}
	}
	
	cout << nest << " " << fin << " " << mxlen <<  " " << fim << endl;
	
	return 0;
}
