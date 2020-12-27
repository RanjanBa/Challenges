#include <bits/stdc++.h>

using namespace std;

int n, src, dst, K;
vector<array<int, 2>> paths[100];

bool visited[100];

int dfs(int cost, int index, int k) {
	if(index == dst && k >= 0) {
		return cost;
	}
	
	if(k < 0) {
		return 1e9;
	}
	
	visited[index] = true;
	
	int ans = 1e9;
	for(array<int, 2> p: paths[index]) {
		if(!visited[p[0]])
			ans = min(ans, dfs(cost + p[1], p[0], k - 1));
	}
	
	visited[index] = false;
	return ans;
}

int findCheapestPrice() {
	for(int i = 0; i < n; i++) {
		visited[i] = false;
	}
	
	int ans = dfs(0, src, K + 1);
	return ans >= 1e9 ? -1 : ans;
}

int main(int argc, char **argv)
{
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u , v, c;
		cin >> u >> v >> c;
		
		paths[u].push_back({v, c});
	}
	
	for(int i = 0; i < n; i++) {
		cout << "u-" << i << ": ";
		for(array<int, 2> v: paths[i]) {
			cout << v[0] << " ";
		}
		
		cout << endl;
	}
	
	cin >> src >> dst >> K;
	
	cout << findCheapestPrice() << endl;
	
	return 0;
}

