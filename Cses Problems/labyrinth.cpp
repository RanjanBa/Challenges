#include<bits/stdc++.h>
#define ll long long
//#define push push_back
//#define pop pop_back
#define ar array

using namespace std;

const int mxN = 1e3;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};

int n, m, si, sj, fi, fj, d[mxN][mxN];
string s[mxN], p[mxN];

bool e(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		
		for(int j = 0; j < m; j++) {
			if(s[i][j] == 'A') {
				si = i, sj = j;
			} else if(s[i][j] == 'B') {
				fi = i, fj = j;
				s[i][j] = '.';
			}
		}
		
		p[i] = string(m, 0);
	}
	
	queue<ar<int, 2>> qu;
	qu.push({si, sj});
	
	while(qu.size()) {
		ar<int, 2> c = qu.front();
		qu.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = c[0] + di[k], nj = c[1] + dj[k];
			
			if(!e(ni, nj))
				continue;
				
			qu.push({ni, nj});
			s[ni][nj] = '#';
			d[ni][nj] = k;
			p[ni][nj] = dc[k];
		}
	}

	if(p[fi][fj]) {
		cout << "YES" << endl;
		string t;
		
		while(fi^si || fj ^ sj) {
			char c = p[fi][fj];
			t += c;
			
			int dd = d[fi][fj]^2;
			fi += di[dd];
			fj += dj[dd];
		}
		
		reverse(t.begin(), t.end());
		cout << t.size() << endl;
		cout << t << endl;
	} else {
		cout << "NO" << endl;
	}
	
    return 0;
}

