#include<bits/stdc++.h>

using namespace std;

struct Node {
	char ch;
	bool end;
	Node* child[26];
	string word;
};

struct Node *generate(char c) {
	Node *n = new Node;
	n->ch = c;
	n->end = false;
	n->word = "";
	for(int i = 0; i < 26; i++) {
		n->child[i] = NULL;
	}
	
	return n;
}

Node* root = generate('/');

void insert(string s) {
	Node* cur = root;
	
	int i = 0;
	
	while(s[i]) {
		int c = s[i] - 'a';
		
		if(cur->child[c] == NULL) {
			cur->child[c] = generate(s[i]);
		}
		cur = cur->child[c];
		i++;
	}
	
	cur->end = true;
	cur->word = s;
}

int n, m = 0;
vector<string> ans;

void dfs(vector<vector<char>>& board, int i, int j, Node *cur) {
	
	int index = board[i][j] - 'a';
	
	if(board[i][j] == '$' || cur->child[index] == NULL) {
		return;
	}
	cout << cur->ch << endl;
	cur = cur->child[index];
	
	if(cur->end) {
		ans.push_back(cur->word);
		cur->end = false;
	}
	
	char ch = board[i][j];
	board[i][j] = '$';
	
	if(i > 0) {
		dfs(board, i-1, j, cur);
	}
	
	if(i + 1 < n) {
		dfs(board, i+1, j, cur);
	}
	
	if(j - 1 >= 0) {
		dfs(board, i, j-1, cur);
	}
	
	if(j+1 < m) {
		dfs(board, i, j+1, cur);
	}

	board[i][j] = ch;
}

int main() {
	
	vector<string> v = {"oath","pea","eat","rain"};
	
	for(int w = 0; w < v.size(); w++) {
		insert(v[w]);
	}
	
	vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	
	n = board.size();
	m = board[0].size();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dfs(board, i, j, root);
		}
	}
	
	cout << "ans: ";
	for(string s: ans) {
		cout << s << ", ";
	}
	cout <<  endl;
	return 0;
}
