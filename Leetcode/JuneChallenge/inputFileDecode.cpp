#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
	string text;
	ifstream inputFile("input_test.txt");
	
	while (getline (inputFile, text)) {
		cout << text << endl;
		string t;
		int count = 0;
		for(char c: text) {
			if(c == '"') {
				//if(t[t.size() - 1] != '\n') {
					//t += " ";
				//}
				t += '\'';
			} else if(c == '[') {
				t += "{";
			} else if(c == ']') {
				t += "}";
				//t += '\n';
				//count++;
			} else {
				t += c;
			}
		}
		
		cout << t;
		cout << count << endl;
	}
	
	return 0;
}
