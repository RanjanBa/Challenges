#include <bits/stdc++.h>
#define ll long long
#define ar array

using namespace std;

const int mxN = 2500;

int n, m;
ll score[mxN], d[mxN];
vector<ar<ll, 2>> g[mxN];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		ll a, b, x;
		cin >> a >> b >> x, a--, b--;

		g[a].push_back({b, x});
	}

	for (int i = 0; i < n; i++)
		d[i] = -1e18;

	d[0] = 0;

	for (int i = 0; i < 2 * n; i++)
	{
		for (int u = 0; u < n; u++)
		{
			for (auto t : g[u])
			{
				ll v = t[0], x = t[1];
				if (d[u] + x > d[v])
				{
					d[v] = d[u] + x;
				}
			}
		}

		score[i] = d[n - 1];
	}

	if (n > 1 && score[n - 2] < score[n - 1])
	{
		cout << -1 << endl;
	}
	else
	{
		cout << score[n - 1] << endl;
	}

	return 0;
}
