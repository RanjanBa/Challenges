#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

void printArr(vector<int> &first, vector<int> &second) {
	cout << "YES" << endl;
	int s = first.size();
	cout << s << endl;
	for(int i = 0; i < s; i++) {
		cout << first[i] << " ";
	}
	cout << endl;
	
	s = second.size();
	cout << s << endl;
	for(int i = 0; i < s; i++) {
		cout << second[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	
	cin >> n;
	vector<int> first, second;
	
	if(n % 4 == 0) {
		for(int i = 0; i < n; i += 4) {
			first.pb(i+1), first.pb(i+4);
			second.pb(i+2), second.pb(i+3);
		}
		
		printArr(first, second);
	} else if((n - 3) % 4 == 0) {
		first.pb(1), first.pb(2);
		second.pb(3);
		for(int i = 7; i <= n; i += 4) {
			first.pb(i - 2), first.pb(i-1);
			second.pb(i - 3), second.pb(i);
		}
		
		printArr(first, second);
	} else {
		cout << "NO" << endl;
	}
	
    return 0;
}

