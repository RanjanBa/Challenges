#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()


using namespace std;

void solve() {
	string str;
	
	cin >> str;
	
	string kickStr = "KICK", startStr = "START";
	int n = str.size(), start = 0;
	
	ll res = 0;
	for(int i = n-1; i >= 0; i--) {
		int isStart = 1;
		for(int j = 0; j < 5; j++) {
		    if(i + j >= n) {
		        isStart = 0;
		        break;
		    }
			if(startStr[j] != str[i+j]) {
				isStart = 0;
				break;
			}
		}
		
		start += isStart;
		
		bool isKick = true;
		for(int j = 0; j < 4; j++) {
		    if(i + j >= n) {
		        isKick = false;
		        break;
		    }
			if(kickStr[j] != str[i+j]) {
				isKick = false;
				break;
			}
		}
		
		if(isKick) {
			res += start;
		}
	}
	
	cout << res << endl;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
