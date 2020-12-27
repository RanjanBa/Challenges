#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()

using namespace std;

ll l, r;

vector<int> getDigits(ll n) {
	vector<int> digits;
	
	//cout << n << ", digits: ";
	while(n) {
		int rem = n % 10;
		digits.push_back(rem);
		n /= 10;
	}
	
	reverse(digits.begin(), digits.end());
	
	//for(int i = 0; i < (int)digits.size(); i++) {
		//cout << digits[i] << " ";
	//}
	
	//cout << endl;
	
	return digits;
}

bool check(ll n) {
	vector<int> digits = getDigits(n);
	
	for(int i = 1; i <= (int)digits.size(); i++) {
		if(i & 1) {
			if((digits[i-1] & 1) == 0) {
				return false;
			}
		} else {
			if(digits[i-1] & 1) {
				return false;
			}
		}
	}
	
	return true;
}

// it will count all boring numbers from 1
ll countBoringNumbers(ll n) {
	vector<int> digits = getDigits(n);
	
	ll cnt = 0;
	
	int si = digits.size();
	if(si == 0) return cnt;
	
	for(int i = 1; i < si; i++) {
		cnt += pow(5, i);
	}
	
	bool canAdd = true;
	
	for(int i = 1; i < si && canAdd; i++) {
		int j = i & 1 ? 1 : 0;
		ll prev = 0;
		while(j < digits[i-1]) {
			j += 2;
			prev++;
		}
		
		int p = si - i;
		cnt += prev * pow(5, p);
		
		if(i & 1) {
			if((digits[i-1] & 1) == 0) {
				canAdd = false;
			}
		} else {
			if(digits[i-1] & 1) {
				canAdd = false;
			}
		}
	}
	
	if(canAdd) {
		int j = si & 1 ? 1  : 0;
		while(j <= digits[si-1]) {
			cnt++;
			j+=2;
		}
	}
	
	//cout << n << " cnt: " << cnt << endl;
	return cnt;
}

void solve() {
	cin >> l >> r;
	ll cnt1 = countBoringNumbers(r);
	ll cnt2 = countBoringNumbers(l-1);
	
	//ll cnt = 0;
	//for(ll i = l; i <= r; i++) {
		//if(check(i)) {
			//cnt++;
		//}
	//}
	
	//cout << cnt << " : " << cnt1 << ", " << cnt2 << endl;
	
	cout << (cnt1 - cnt2) << endl;
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
