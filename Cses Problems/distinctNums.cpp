#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	set<int> s;
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	
	cout << s.size() << endl;	
	
    return 0;
}

