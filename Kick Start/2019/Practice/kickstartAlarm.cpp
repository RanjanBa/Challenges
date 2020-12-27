#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1000000007;

void solve() {
	int N, K, x1, y1, C, D, E1, E2, F;
	cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;
		
	vector<int> A(N + 1);

	A[1] = (x1 + y1) % F;
	
	for(int i = 2; i <= N; i++) {
		//xi = ( C × xi-1 + D × yi-1 + E1 ) modulo F.
		//yi = ( D × xi-1 + C × yi-1 + E2 ) modulo F.
		
		int prev_x1 = x1, prev_y1 = y1;
		
		x1 = ((C * prev_x1) % F + (D * prev_y1) % F + E1) % F;
		y1 = ((D * prev_x1) % F + (C * prev_y1) % F + E2) % F;
		
		A[i] = (x1 + y1) % F;
	}
	
	for(int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
	ll ans = 0;
	
	//naive approach
	//for(int l = 1; l <= N; l++) {
		//for(int i = 1; i <= N - l + 1; i++) {
			//for(int j = i; j < i + l; j++) {
				//for(int k = 1; k <= K; k++) {
					//long long temp = pow(j - i + 1, k) * 1LL;
					//ans = (ans + A[j] * (temp % MODULO)) % MOD;
				//}
			//}
		//}
	//}
	
	ll gSum = K;
	
	for(ll i = 1; i <= N; i++) {
		ll t = 0;
		if(i != 1) {
			//t = (((ll)pow(i, (ll)K + 1) - i) % MOD) * ((ll)pow(i - 1, MOD - 2) % MOD);
			t = pow(i - 1, MOD - 2);
			gSum = (gSum + t) % MOD;
		}
		ans = ans + gSum * A[i];
		ans %= MOD;
		cout << "g sum: " << gSum << ", a: " << A[i] << ", t: " << t << ", res: " << ans << endl;
	}
	
	cout << ans << endl;
}

int main(int argc, const char* argv[]) {
	int T;
	
	cin >> T;
	
	for(int t = 1; t <= T; t++) {
		cout << "Case #"<< t << ": ";
		solve();
	}
	
	return 0;
}
