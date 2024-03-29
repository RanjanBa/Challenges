#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define rep(i, s, x, inc) for (int i = s; i < x; i += inc)
#define repr(i, e, x, dec) for (int i = x - 1; i >= e; i -= dec)
#define repv(v, li) for (auto v : li)
#define sz(li) (int)li.size()
#define all(v) v.begin(), v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li, v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template <typename T>
inline void debug(const T li[], int n)
{
    rep(i, 0, n, 1)
    {
        cout << li[i] << " ";
    }

    cout << "\n";
}

template <typename T>
inline void debug(vector<T> li)
{
    repv(v, li)
    {
        cout << v << " ";
    }

    cout << "\n";
}

template <typename T>
inline void debug(vector<vector<T>> li)
{
    repv(v1, li)
    {
        repv(v2, v1)
        {
            cout << v2 << " ";
        }

        cout << "\n";
    }
}

// ------ main function ------

const int mxN = 100;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

string s[mxN];

void solve()
{
    int n, m;
    cin >> n >> m;

    int miX = INF, miY = INF;
    int mxX = -INF, mxY = -INF;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];

        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '*')
            {
                miX = min(miX, i);
                miY = min(miY, j);
                mxX = max(mxX, i);
                mxY = max(mxY, j);
            }
        }
    }

    if (s[miX][miY] != '*')
    {
        cout << (miX + 1) << " " << (miY + 1) << "\n";
        return;
    }

    if (s[miX][mxY] != '*')
    {
        cout << (miX + 1) << " " << (mxY + 1) << "\n";
        return;
    }

    if (s[mxX][miY] != '*')
    {
        cout << (mxX + 1) << " " << (miY + 1) << "\n";
        return;
    }

    cout << (mxX + 1) << " " << (mxY + 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}