#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()

using namespace std;

const int mxN = 5e4+10;
const int INF = 1e9;

int n, q;

/*
vector<int> chs[26];
vector<int> g[mxN];

string strs[mxN];

int vis[mxN];

int dist[mxN][mxN];

int query(int s, int e) {
	memset(vis, 0, sizeof(vis));
	queue<arr<int, 2>> qu;
	qu.push({s, 1});
	vis[s] = 1;
	
	while(qu.size()) {
		arr<int,2> tp = qu.front();
		qu.pop();
		
		int u = tp[0], d = tp[1];
		
		//cout << "u: " << u << ", d: " << d << endl;
		if(u == e) return d;
		
		for(int v : g[u]) {
			if(vis[v] == 0) {
				qu.push({v, d + 1});
				vis[v] = 1;
			}
		}
	}

	return -1;
}

void floydWarshall() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for(int j : g[i]) {
			dist[i][j] = 1;
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	//cout << "\nDist:\n";
	//for(int i = 1; i <= n; i++) {
		//for(int j = 1; j <= n; j++) {
			//cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
		//}
		
		//cout << endl;
	//}
}

void solve() {
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) {
		cin >> strs[i];
		//strs[i] = "TEST";
		
		memset(vis, 0, sizeof(vis));
		
		for(char ch : strs[i]) {
			int k = ch - 'A';
			if(vis[k] == 0) {
				chs[k].push_back(i);
			}
			
			vis[k] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		for(char ch : strs[i]) {
			int k = ch - 'A';
			
			for(int v : chs[k]) {
				if(i == v) continue;
				if(vis[v] == 0) {
					g[i].push_back(v);
					vis[v] = 1;
				}
			}
		}
	}
	
	//cout << endl;
	//for(int i = 1; i <= n; i++) {
		//cout << i << " : ";
		
		//for(int v: g[i]) cout << v << " ";
		
		//cout << endl;
	//}

	floydWarshall();

	for(int i = 0; i < q; i++) {
		int s, e;
		cin >> s >> e;
		//s = 1, e = 100;
		//cout << s << ", " << e << endl;
		cout << (dist[s][e] == INF ? -1 : (dist[s][e] + 1)) << " ";
	}
	
	cout << endl;
	
	
	for(int i = 0; i < 26; i++) {
		chs[i].clear();
	}
	
	for(int i = 1; i <= n; i++) {
		g[i].clear();
	}
}
*/


int vis[26];
string strs[mxN];
vector<int> g[26];
int dist[26][26];

void solve() {
	cin >> n >> q;
	
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < n; i++) {
		cin >> strs[i];
		
		vector<char> newChs;
		vector<char> oldChs;
		
		int dup[26];
		memset(dup, 0, sizeof(dup));
		
		for(char ch : strs[i]) {
			int k = ch - 'A';
			if(dup[k] == 0) {
				//if(vis[k] == 0) {
					newChs.push_back(k);
				//} else {
					//oldChs.push_back(k);
				//}
				dup[k] = 1;
			}
		}
		
		string newStr = "";
		for(int j : newChs) {
			newStr.push_back((char)('A' + j));
			for(int k : newChs) {
				if(j == k) continue;
				
				g[j].push_back(k);
			}
			
			vis[j] = 1;
		}
		
		//string oldStr;
		
		//for(int j : oldChs) {
			//oldStr.push_back((char)('A' + j));
			//for(int k : newChs) {
				//g[j].push_back(k);
				//g[k].push_back(j);
			//}
		//}
		
		//cout << "new: " << newStr << ", old: " << oldStr << endl;
	}
	
	for(int i = 0; i < 26; i++) {
		cout << (char)('A' + i) << " : ";
		for(int j : g[i]) {
			cout << (char)('A' + j) << " ";
		}
		cout << endl;
	}
	
	//floyd warshall algo
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			dist[i][j] = INF;
		}
	}
	
	for(int i = 0; i < 26; i++) {
		dist[i][i] = 0;
		for(int j : g[i]) {
			dist[i][j] = 1;
		}
	}
	
	for(int k = 0; k < 26; k++) {
		for(int i = 0; i < 26;  i++) {
			for(int j = 0; j < 26; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	cout << "  ";
	for(int i = 0; i < 26; i++) {
		cout << (char)('A' + i) << " ";
	}
	cout << endl;
	for(int i = 0; i < 26; i++) {
		cout << (char)('A' + i) << " ";
		for(int j = 0; j < 26; j++) {
			if(dist[i][j] == INF) {
				cout << 'a';
			} else {
				cout << dist[i][j];
			}
			cout << " ";
		}
		
		cout << endl;
	}
	
	while(q--) {
		int s, e = 0;
		cin >> s >> e, s--, e--;
		
		vector<int> first;
		
		memset(vis, 0, sizeof(vis));
		for(char ch : strs[s]) {
			int k = ch - 'A';
			if(vis[k] == 0) {
				first.push_back(k);
				vis[k] = 1;
			}
		}
		
		vector<int> second;
		
		memset(vis, 0, sizeof(vis));
		for(char ch : strs[e]) {
			int k = ch - 'A';
			if(vis[k] == 0) {
				second.push_back(k);
				vis[k] = 1;
			}
		}
		
		int res = INF;
		
		for(int i : first) {
			for(int j : second) {
				res = min(res, dist[i][j]);
			}
		}
		res = res == INF ? -1 : (res + 2);
		cout << res << " ";
	}
	cout << endl;
	for(int i = 0; i < 26; i++) {
		g[i].clear();
	}
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
