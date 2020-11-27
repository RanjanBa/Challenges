#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char* argv[]) {
    int t, n;
    
    string s;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cin >> n;
        cin >> s;
        int m = (n + 1) >> 1;
        
        int cur_beauty = 0, max_beauty = 0;
        
        for(int j = 0; j < m; j++) {
           int b = (int)s[j] - (int)'0';
           cur_beauty += b;
        }
        
        max_beauty = cur_beauty;
        for(int j = m; j < n; j++) {
			int b = (int)s[j - m] - (int)'0';
			cur_beauty -= b;
			
			b = (int)s[j] - (int)'0';
			cur_beauty += b;
			max_beauty = max(max_beauty, cur_beauty);
		}
		
		cout << "Case #" << i << " " << max_beauty << endl;
    }
}
