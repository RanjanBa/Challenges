#include<bits/stdc++.h>

using namespace std;

#define ld long double
//typedef long double ld

// non optimize solution mle error
//void solve() {
	//cout << fixed << setprecision(9);
	//int w, h, l, u, r, d;
	//cin >> w >> h >> l >> u >> r >> d;
	
	//l--, u--, r--, d--;
	
	//vector<vector<ld>> grid(h, vector<ld>(w));
	
	//for(int i = 0; i < h; i++)
		//for(int j = 0; j < w; j++)
			//grid[i][j] = 0.0;
			
	//grid[h-1][w-1] = 1.0;
	
	//for(int i = h-2; i >= 0; i--) {
		//if(l <= w-1 && w-1 <= r && u <= i && i <= d) {
			//grid[i][w-1] = 0.0;
		//} else {
			//grid[i][w-1] = grid[i+1][w-1];
		//}
	//}
	
	//for(int i = w-2; i >= 0; i--) {
		//if(l <= i && i <= r && u <= h-1 && h-1 <= d) {
			//grid[h-1][i] = 0.0;
		//} else {
			//grid[h-1][i] = grid[h-1][i+1];
		//}
	//}
	
	//for(int i = h - 2; i >= 0; i--) {
		//for(int j = w-2; j >= 0; j--) {
			//if(l <= j && j <= r && u <= i && i <= d) {
				//grid[i][j] = 0.0;
			//} else {
				//grid[i][j] = 0.5 * grid[i][j+1] + 0.5 * grid[i+1][j];
			//}
		//}
	//}
	
	//cout << "\n";
	//for(int i = 0; i < h; i++) {
		//for(int j = 0; j < w; j++) {
			//cout << grid[i][j] << " ";
		//}
		
		//cout << endl;
	//}
	
	//ld ans = grid[0][0];
	
	//cout << ans << endl;
//}

// non optimize solution tle error
//void solve2() {
	//cout << fixed << setprecision(9);
	//int w, h, l, u, r, d;
	//cin >> w >> h >> l >> u >> r >> d;
	//l--, u--, r--, d--;
	
	//vector<ld> dp(w);
	
	//for(int i = w-1; i >= 0; i--) {
		//if(l <= i && i <= r && u <= h-1 && h-1 <= d) {
			//dp[i] = 0.0;
		//} else if(i == w - 1){
			//dp[i] = 1.0;
		//} else {
			//dp[i] = dp[i+1];
		//}
	//}
	
	//for(int i = h-2; i >= 0; i--) {
		//for(int j = w - 1; j >= 0; j--) {
			//if(l <= j && j <= r && u <= i && i <= d) {
				//dp[j] = 0.0;
			//} else if(j != w - 1) {
				//dp[j] = dp[j+1] + dp[j];
				//dp[j] *= 0.5;
			//}
		//}
	//}
	
	//ld ans = dp[0];
	
	//cout << ans << endl;
//}

const int mxN = 3e5 + 1;
ld fac[mxN], pow2[mxN];


void calc() {
	fac[0] = pow2[0] = 0.0;
	for(int i = 1; i < mxN; i++) {
		fac[i] = fac[i-1] + (ld)log(i);
		pow2[i] = pow2[i-1] + (ld)log(2);
	}
}

ld calCom(int n, int k) {
	return exp(fac[n] - fac[k] - fac[n-k] - pow2[n]);
}

void solve() {
	int w, h, l, u, r, d;
	
	cin >> w >> h >> l >> u >> r >> d;
	
	ld ans = 0.0;
	
	int ly = u, lx = r;
		
	if(r < w && u > 1) {
		ld mult = 1.0;
		while(ly > 1) {
			ly--;
			lx++;
			if(lx > w) {
				lx = w;
				mult = 0.5;
			}
			
			ans += mult * calCom(lx + ly - 2, lx-1);
		}
	}
	
	ly = d, lx = l;
	
	if(d < h && l > 1) {
		ld mult = 1.0;
		while(lx > 1) {
			ly++;
			lx--;
			if(ly > h) {
				ly = h;
				mult = 0.5;
			}
			
			ans += mult * calCom(lx + ly - 2, lx-1);
		}
	}
	cout << fixed << setprecision(9) << ans << endl;
}

int main() {
    int T;
    cin >> T;
    
    calc();
    
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": "; 
        solve();
    }
    
    return 0;
}
