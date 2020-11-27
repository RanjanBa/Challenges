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

map<char, int> precedence = { {'+',1}, {'-',1}, {'*',2}, {'/',3}, {'^',4} };

bool check(const char a, const char b) {
	if(precedence[a] <= precedence[b])
		return true;

	return false;
}

void solve() {
	int n;
	cin >> n;
	
	string str;
	
	cin >> str;
	
	stack<char> stk;
	FOR(i, n) {
		if(str[i] == '(') {
			stk.push(str[i]);
		} else if(str[i] == ')') {
			while(stk.size()) {
				if(stk.top() == '(') {
					stk.pop();
					break;
				}
				cout << stk.top();
				stk.pop();
			}
		} else if('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		} else {
			while(stk.size() && stk.top() != '(' && check(str[i], stk.top())) {
				cout << stk.top();
				stk.pop();
			}
			
			stk.push(str[i]);
		}
	}
	
	while(stk.size()) {
		cout << stk.top();
		stk.pop();
	}
	
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        //cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}

