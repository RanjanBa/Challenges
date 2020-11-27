#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

set<ar<int, 2>> bot, top;

void add (ar<int, 2> x) {
	int bs = bot.size(), ts = top.size();
	if(bs == 0 && ts == 0) {
		bot.insert(x);
		return;
	}
	
	if(bs == ts) {
		auto it = top.begin();
		if(x[0] > (*it)[0]) {
			top.insert(x);
			top.erase(it);
			bot.insert(*it);
		} else {
			bot.insert(x);
		}
	} else if(bs > ts) {
		auto it = --bot.end();
		
		if(x[0] < (*it)[0]) {
			bot.insert(x);
			bot.erase(it);
			top.insert(*it);
		} else {
			top.insert(x);
		}
	} else {
		//assert()
	}
}

void remove(ar<int, 2> x) {
	int bs = bot.size(), ts = top.size();
	
	if(bs == ts) {
	 	auto it = bot.find(x);
	 	if(it != bot.end()) {
			bot.erase(it);
			
			it = top.begin();
			
			bot.insert(*it);
			top.erase(it);
		} else {
			it = top.find(x);
			
			if(it != top.end()) {
				top.erase(it);
			}
		}
	} else if(bs > ts) {
		auto it = bot.find(x);
		if(it != bot.end()) {
			bot.erase(it);
		} else {
			it = top.find(x);
			
			if(it != top.end()) {
				top.erase(it);
				it = --bot.end();
				
				top.insert(*it);
				bot.erase(it);
			}
		}
	}
}

//void printArray() {
	//for(auto it: bot) {
		//cout << it[0] << " ";
	//}
	
	//cout << ", ";
	
	//for(auto it: top) {
		//cout << it[0] << " ";
	//}
	
	//cout << endl;
//}

int main() {
	int n, k;
	
	cin >> n >> k;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for(int i = 0; i < k - 1; i++) {
		add({v[i], i});
	}
	
	for(int i = k - 1; i < n; i++) {
		add({v[i], i});
		cout << (*--bot.end())[0] << " ";
		remove({v[i - k + 1], i - k + 1});
	}
	
	cout << endl;
	
    return 0;
}

