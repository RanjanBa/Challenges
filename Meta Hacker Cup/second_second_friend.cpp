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

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve()
{
    int r, c;
    cin >> r >> c;

    cout << r << " , " << c << "\n";

    int trees = 0;
    vector<string> str(r);
    for (int i = 0; i < r; i++)
    {
        cin >> str[i];
        for (int j = 0; j < c; j++)
        {
            if (str[i][j] == '^')
            {
                trees++;
            }
        }
    }

    if (trees == 0)
    {
        cout << "Possible\n";
        for (int i = 0; i < r; i++)
        {
            cout << str[i] << "\n";
        }

        return;
    }

    if (r == 1 || c == 1)
    {
        cout << "Impossible\n";
        return;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (str[i][j] == '.')
            {
                str[i][j] = '^';
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        cout << str[i] << "\n";
    }
    

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int cnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int x = i + di[k], y = j + dj[k];

                if (x >= 0 && x < r && y >= 0 && y < c)
                {
                    if (str[x][y] == '^')
                    {
                        cnt++;
                    }
                }
            }

            cout << "(" << i << "," << j <<  ") cnt : " << cnt  << "\n";

            if (cnt < 2)
            {
                cout << "Impossible\n";
                return;
            }
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < r; i++)
    {
        cout << str[i] << "\n";
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
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}