#include <bits/stdc++.h>
using namespace std;

const int mxN = 510, INF = 1e9;
int vec[mxN];

int dfs(int u, int e)
{
    if (u < e)
    {
        return INF;
    }

    if (u == e)
    {
        return 0;
    }

    return dfs(vec[u], e) + 1;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        cin >> vec[i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int ans = dfs(i, j);
            if (ans >= INF)
            {
                continue;
            }

            if (ans != 0)
            {
                cout << i << " " << j << " " << ans << " ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}