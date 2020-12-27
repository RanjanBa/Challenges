#include<bits/stdc++.h>
#define ll long long
//#define push push_back
//#define pop pop_back
#define ar array

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	stack<int> s;
	
	for(int i = 0; i < n; i++) {
		
		while(!s.empty() && v[s.top()] >= v[i]) {
			s.pop();
		}
		
		int index = 0;
		if(!s.empty()) {
			index = s.top() + 1;
		}
		
		cout << index << " ";
		s.push(i);
	}
	
	cout << endl;
	
    return 0;
}

