#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	
	getline(cin, str);
	
	while(str.size()) {
		vector<string> words;
		words.push_back("");
		
		int i = 0;
		
		while(i < (int)str.size()) {
			if(str[i] == ' ') {
				words.push_back("");
			} else {
				words.back() += str[i];
			}
			i++;
		}
		
		//cout << words[0] << ", " << words[1] << endl;
		
		bool found = false;
		for(i = 0; i <= (int)words[0].size()-(int)words[1].size(); i++) {
			bool flag = true;
			for(int j = 0; j < (int)words[1].size() && flag; j++) {
				if(words[0][i+j] != words[1][j]) {
					flag = false;
				}
				
			}
			
			if(flag) {
				found = true;
				break;
			}
		}
		
		if(found) cout << 1 << endl;
		else cout << 0 << endl;
		
		getline(cin, str);
	}
	
	return 0;
}
