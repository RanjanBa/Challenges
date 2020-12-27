#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b;
	cin >> a >> b >> n;
	
	//for(int i = a + 1; i <= b; i++) {
         //cout << i << endl;
         //string s;
         //cin >> s;
         //if(s == "CORRECT") {
             //break;
         //}
     //}
	
	a++;
	while(a <= b) {
		int m = a + (b - a) / 2;
		
		cout << m << endl;
		string s;
		cin >> s;
		
		if(s == "CORRECT")
		{
			break;
		}
		
		if(s == "TOO_SMALL") {
			a = m + 1;
		} else if(s == "TOO_BIG")  {
			b = m - 1;
		} else {
			exit(0);
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		solve();
	}
}
