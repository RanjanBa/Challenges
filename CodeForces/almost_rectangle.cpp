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

const int mxN = 400;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

char a[mxN][mxN];

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < sz(str); j++)
        {
            a[i][j] = str[j];
            if (str[j] == '*')
            {
                vec.phb({i, j});
            }
        }
    }

    if (vec[0].first == vec[1].first)
    {
        int idx = 0;
        if (vec[0].first == 0)
        {
            idx = 1;
        }

        a[idx][vec[0].second] = '*';
        a[idx][vec[1].second] = '*';
    }
    else if (vec[0].second == vec[1].second)
    {
        int idx = 0;

        if (vec[0].second == 0)
        {
            idx = 1;
        }

        a[vec[0].first][idx] = '*';
        a[vec[1].first][idx] = '*';
    }
    else
    {
        a[vec[0].first][vec[1].second] = '*';
        a[vec[1].first][vec[0].second] = '*';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        solve();
    }

    return 0;
}
