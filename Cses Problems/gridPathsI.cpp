#include<bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 7, MOD = 1e9 + 7;

string path;

int vis[mxN][mxN];

int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};


bool can(int i, int j) {
	return i >= 0 && j >= 0 && i < mxN && j < mxN && vis[i][j] == 0;
}

int findPath(int i, int j, int idx) {
	if(i == mxN - 1 && j == 0) {
		if(idx == 48) {
			return 1;
		}
		return 0;
	}
	
    bool t = (j > 0 && j < 6 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 &&
				((i == 0 && vis[i + 1][j]) || (i == 6 && vis[i - 1][j])))
			 || (i > 0 && i < 6 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 &&
				((j == 0 && vis[i][j + 1]) || (j == 6 && vis[i][j - 1])))
             || (i > 0 && i < 6 && j > 0 && j < 6 && vis[i - 1][j] && vis[i + 1][j] && vis[i][j - 1] == 0 && vis[i][j + 1] == 0)
             || (i > 0 && i < 6 && j > 0 && j < 6 && vis[i][j - 1] && vis[i][j + 1] && !vis[i - 1][j] && !vis[i + 1][j]);
	
	if(t) return 0;
	
	vis[i][j] = 1;
	
	int res = 0;
	
	if(path[idx] == '?') { 
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];
			
			if(can(ni, nj)) {
				res += findPath(ni, nj, idx + 1);
			}
		}
	} else {
		int k = 0;
		
		switch (path[idx])
		{
			case 'D':
				k = 0;
				break;
			case 'R':
				k = 1;
				break;
			case 'U':
				k = 2;
				break;
			default:
				k = 3;
				break;
		}
		
		int ni = i + di[k], nj = j + dj[k];
		
		if(can(ni, nj)) {
			res += findPath(ni, nj, idx + 1);
		}
	}
	
	vis[i][j] = 0;
	
	return res;
}

int main() {
	cin >> path;
	
	memset(vis, 0, sizeof(vis));	
	
	int res = findPath(0, 0, 0);

	cout << res << endl;
	
    return 0;
}

