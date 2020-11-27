#include<bits/stdc++.h>

using namespace std;

#define all x.begin(), x.end()

//map<string, int> mp;

//brute force approach MLE error
//void solve() {
		//int n, k;
	
    //cin >> n >> k;
    
    //vector<string> vec(n);

    //for(int i = 0; i < n; i++) {
		//cin >> vec[i];
	//}
	
	//for(int i = 0; i < n; i++) {
		//for(int l = 1; l <= (int)vec[i].size(); l++) {
			//string str = vec[i].substr(0, l);
			
			//if(mp.count(str)) {
				//mp[str]++;
			//} else {
				//mp[str] = 1;
			//}
		//}
	//}
	//for(auto it: mp) {
		//cout << it.first << ": " << it.second << endl;
	//}
	//int ans = 0;
	
	//for(int i = 0; i < n; i++) {
		//for(int l = 1; l <= (int)vec[i].size(); l++) {
			//string str = vec[i].substr(0, l);
			
			//if(mp.count(str)) {
				//ans += mp[str] / k;
			//}
			
			//mp.erase(str);
		//}
	//}
	
    //cout << ans << endl;
    
    //mp.clear();
//}

struct Node {
	int cnt;
	Node* children[26];
};

class Trie {
private:
	Node* root;
	Node* getNode() {
		Node* nd = new Node;
		for(int i = 0; i < 26; i++) {
			nd->children[i] = NULL;
		}
		nd->cnt = 0;
		
		return nd;
	}
public:
	Trie() {
		root = getNode();
	}
	
	void insert(string str) {
		Node* cur = root;
		for(int i = 0; i < (int)str.size(); i++) {
			int index = str[i] - 'A';
			if(cur->children[index] == NULL) {
				Node* nd = getNode();
				nd->cnt = 1;
				cur->children[index] = nd;
			} else {
				cur->children[index]->cnt++;
			}
			
			cur = cur->children[index];
		}
	}
	
	int getSum(string str, int k) {
		Node* cur = root;
		
		int ans = 0;
		for(int i = 0; i < (int)str.size(); i++) {
			int index = str[i] - 'A';
			if(cur->children[index] != NULL) {
				ans += cur->children[index]->cnt / k;
				cur->children[index]->cnt = 0;
			}			
			
			cur = cur->children[index];
		}
		
		return ans;
	}
};

void solve() {
	int n, k;
	
    cin >> n >> k;
    
    vector<string> vec(n);

    for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	Trie* trie = new Trie;
	
	for(int i = 0; i < n; i++) {
		trie->insert(vec[i]);
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		ans += trie->getSum(vec[i], k);
	}
	
    cout << ans << endl;
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
