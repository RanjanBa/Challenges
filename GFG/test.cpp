#include <iostream>
using namespace std;

const int mxN = 50, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int n, m, vis[mxN][mxN];
char mat[mxN][mxN];

bool check(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 'X' && vis[i][j] == 0;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + di[k], nj = j + dj[k];

        if (check(ni, nj))
        {
            dfs(ni, nj);
        }
    }
}

void solve()
{
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = str[j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] || mat[i][j] == 'O')
                continue;

            dfs(i, j);
            res++;
        }
    }

    cout << res << "\n";
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