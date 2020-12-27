#include<bits/stdc++.h>

using namespace std;

struct turn{
	string seq = "0000";
	int depth = 0;
};

int openLock(vector<string>& deadends, string target) {
	turn cur, old = cur;
	queue<turn> Q;

	set<string> dead(deadends.begin(),deadends.end());
	set<string> visited;
	char c;
	//int dep;
	
	if(dead.count(cur.seq)) return -1;
	
	if (target == cur.seq) return 0;
	
	Q.push(cur);
	visited.insert(cur.seq);
	
	while(!Q.empty()){
		old = Q.front();
		cur = old;
		Q.pop();
		for(int d:{1,-1}){
			for(int i=0;i<4;i++){
				c = cur.seq[i];
				cur.seq[i] = d==1?(c=='9'?'0':c+1):(c=='0'?'9':c-1);
				if(cur.seq == target){
					return old.depth+1;
				}
				else if(!visited.count(cur.seq) && !dead.count(cur.seq)){
					cur.depth = old.depth+1;
					Q.push(cur);
					visited.insert(cur.seq);
				}
				cur.seq[i] = c;
			}
		} 
	}
	return -1;
}

int main() {
	//["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
	vector<string> strs = {"8887","8889","8878","8898","8788","8988","7888","9888"};
	string target = "8888";
	
	cout << openLock(strs, target) << endl;
	
	return 0;
}
