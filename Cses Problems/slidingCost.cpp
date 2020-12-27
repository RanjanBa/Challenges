#include<bits/stdc++.h>
#define ll long long
#define push push_back
#define pop pop_back
#define ar array

using namespace std;

set<ar<int, 2>> bot, top;
ll sb = 0, st = 0;

void add (ar<int, 2> x) {
	int bs = bot.size(), ts = top.size();
	if(bs == 0 && ts == 0) {
		bot.insert(x);
		sb += x[0];
		return;
	}
	
	if(bs == ts) {
		auto it = top.begin();
		if(x[0] > (*it)[0]) {
			top.insert(x);
			st += x[0];
			
			top.erase(it);
			st -= (*it)[0];
			
			bot.insert(*it);
			sb += (*it)[0];
		} else {
			bot.insert(x);
			sb += x[0];
		}
	} else if(bs > ts) {
		auto it = --bot.end();
		
		if(x[0] < (*it)[0]) {
			bot.insert(x);
			sb += x[0];
			
			bot.erase(it);
			sb -= (*it)[0];
			
			top.insert(*it);
			st += (*it)[0];
		} else {
			top.insert(x);
			st += x[0];
		}
	}
}

void remove(ar<int, 2> x) {
	int bs = bot.size(), ts = top.size();
	
	if(bs == ts) {
	 	auto it = bot.find(x);
	 	if(it != bot.end()) {
			bot.erase(it);
			sb -= (*it)[0];
			
			it = top.begin();
			bot.insert(*it);
			sb += (*it)[0];
			
			top.erase(it);
			st -= (*it)[0];
		} else {
			it = top.find(x);
			
			if(it != top.end()) {
				top.erase(it);
				st -= (*it)[0];
			}
		}
	} else if(bs > ts) {
		auto it = bot.find(x);
		if(it != bot.end()) {
			bot.erase(it);
			sb -= (*it)[0];
		} else {
			it = top.find(x);
			
			if(it != top.end()) {
				top.erase(it);
				st -= (*it)[0];
				it = --bot.end();
				
				top.insert(*it);
				st += (*it)[0];
				bot.erase(it);
				sb -= (*it)[0];
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
		int med = (*--bot.end())[0];
		cout << st - med * top.size() + med * bot.size() - sb << " ";
		remove({v[i - k + 1], i - k + 1});
	}
	
	cout << endl;
	
    return 0;
}

