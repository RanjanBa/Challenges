#include<bits/stdc++.h>
#define ll long long
#define arr array
#define phb push_back
#define ppb pop_back
using namespace std;

const int base = 100;

class Node {
	public:
		int x, y;
		vector<Node*> children;
		bool canMove;
		int val() {
			return x * base + y;
		}
};

map<int, Node*> mp;
set<int> vis;

//void printPath(vector<int> v) {
	//for(int p: v) {
		//cout << p << " ";
	//}
	//cout << endl;
//}


//vector<int> pathA, pathB;

bool canMove(Node* root) {
	return vis.find(root->val()) == vis.end() &&
		root->canMove;
}

int dfs(Node* rootA, Node* rootB, int pa, int pb, bool turn = true) {
	bool moveA = false, moveB = false;
	
	for(Node* n : rootA->children) {
		if(canMove(n)) {
			moveA = true;
		}
	}
	
	for(Node* n : rootB->children) {
		if(canMove(n)) {
			moveB = true;
		}
	}
	
	if(!moveA && !moveB) {
		//cout << "a : " << rootA->val() << ", b: " << rootB->val() << "\t";
		//cout << "pa: " << pa << ", pb: " << pb << endl;
		//cout << "Path A: ";
		//printPath(pathA);
		//cout << "Path B: ";
		//printPath(pathB);
		return pa - pb;
	}
	
	//cout << "a : " << rootA->val() << ", b: " << rootB->val() << endl;
	
	int res = turn ? -1e9 : 1e9;
	
	if((turn && moveA) || (!turn && !moveB)) {
		for(Node* n : rootA->children) {
			if(!canMove(n)) continue;
			vis.insert(n->val());
			//pathA.push_back(n->val());
			int t = dfs(n, rootB, pa + 1, pb, false);
			res = turn ? max(res, t) : min(res, t);
			vis.erase(n->val());
			//pathA.pop_back();
		}
	} else if((!turn && moveB) || (turn && !moveA)) {
		for(Node* n : rootB->children) {
			if(canMove(n)) {
				vis.insert(n->val());
				//pathB.push_back(n->val());
				int t = dfs(rootA, n, pa, pb + 1, true);
				res = turn ? max(res, t) : min(res, t);
				//pathB.pop_back();
				vis.erase(n->val());
			}
		}
	}
	
	return res;
}

void solve() {
	int s, c;
	arr<int, 2> a, b;
	cin >> s >> a[0] >> a[1] >> b[0] >> b[1] >> c;
	
	set<int> st;
	for(int i = 0; i < c; i++) {
		int x, y;
		cin >> x >> y;
		st.insert(x * base + y);
	}
	
	for(int i = 1; i <= s; i++) {
		for(int j = 1; j < 2 * i; j++) {
			Node* nn = new Node;
			
			if((j & 1) == 0) {
				Node* t = mp[(i - 1) * base + (j-1)];
				t->children.push_back(nn);
				nn->children.push_back(t);
			}
			
			if(j > 1) {
				Node* t = mp[i * base + (j-1)];
				t->children.push_back(nn);
				nn->children.push_back(t);
			}
			
			int p = i* base + j;
			if(st.find(p) != st.end()) {
				nn->canMove = false;
			} else {
				nn->canMove = true;
			}
			
			nn->x = i, nn->y = j;
			
			mp[p] = nn;
		}
	}
	
	//for(auto it : mp) {
		//Node* n = it.second;
		//cout << it.first << " : ";
		
		//for(Node* ch : n->children)
			//cout << "(" << ch->x  << "," << ch->y << ") ";
		
		//cout << endl;
	//}
	
	Node* rootA = mp[a[0] * base + a[1]];
	Node* rootB = mp[b[0] * base + b[1]];
	
	vis.insert(rootA->val());
	vis.insert(rootB->val());
	//pathA.push_back(rootA->val());
	//pathB.push_back(rootB->val());
	
	int ans = dfs(rootA, rootB, 1, 1);
	
	cout << ans << endl;
	
	//pathA.clear(), pathB.clear();
	mp.clear();
	vis.clear();
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
