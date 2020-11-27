#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m >> a;
	int x = 0;
	x = n / a;
	if(n % a != 0) x++;
		
	int y = m / a;
	if(m % a != 0) y++;
	
	cout << (long long)x * y << endl;
	
	return 0;
}
