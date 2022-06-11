#include <bits/stdc++.h>
#define ll long long
#define phb push_back
#define ppb pop_back
#define ar array

using namespace std;

const int mxN = 1e5;

int n, m, vis[mxN];
ll c1[mxN], c2[mxN];
vector<ar<int, 2>> g1[mxN], g2[mxN];

void bfs(vector<ar<int, 2>> g[mxN], int st, ll cost[mxN])
{
	memset(cost, 0x3f, sizeof(c1));
	memset(vis, 0, sizeof(vis));

	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, st});
	cost[st] = 0;

	while (!pq.empty())
	{
		ar<ll, 2> a = pq.top();
		pq.pop();

		ll u = a[1];
		vis[u] = 1;

		if (a[0] > cost[u])
		{
			continue;
		}

		for (ar<int, 2> p : g[u])
		{
			int v = p[0], tc = p[1];
			if (vis[v])
				continue;

			if (cost[u] + tc < cost[v])
			{
				cost[v] = cost[u] + tc;
				pq.push({cost[v], v});
			}
		}
	}

	// cout << "cost: ";
	// for(int i = 0; i < n; i++) cout << cost[i] << " ";
	// cout << endl;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c, --a, --b;

		g1[a].phb({b, c});
		g2[b].phb({a, c});
	}

	bfs(g1, 0, c1);
	bfs(g2, n - 1, c2);

	ll ans = 1e18;
	for (int i = 0; i < n; i++)
	{
		for (ar<int, 2> a : g1[i])
		{
			ans = min(ans, c1[i] + c2[a[0]] + a[1] / 2);
		}
	}

	cout << ans << endl;

	return 0;
}
