#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define unordered_set uset
#define unordered_map umap

using namespace std;

int main() {
	string s;
	
	cin >> s;
	
	int chs[26] = {};
	
	for(char c: s) {
		chs[c - 'A']++;
	}
	
	int count = 0;
	for(int i = 0; i < 26; i++) {
		count += chs[i] & 1;
	}
	
	if(count > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	
	string half = "";
	for(int i = 0; i < 26; i++) {
		if((chs[i] & 1) == 0) {
			for(int j = 0; j < chs[i] / 2; j++) {
				half += (char)('A' + i);
			}
		}
	}
	
	cout << half;
	
	for(int i = 0; i < 26; i++) {
		if(chs[i] & 1) {
			for(int j = 0; j < chs[i]; j++) {
				cout << (char) ('A' + i);
			}
		}
	}
	
	reverse(half.begin(), half.end());
		
	cout << half << endl;
	
    return 0;
}

