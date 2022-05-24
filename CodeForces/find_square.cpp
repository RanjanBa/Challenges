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

const int mxN = 115;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

string a[mxN];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x = -1, y = -1;

    for (int i = 0; i < n; i++)
    {
        int f = 0, s = m - 1;

        while (f <= s && (a[i][f] == 'W' || a[i][s] == 'W'))
        {
            if (a[i][f] == 'W')
            {
                f++;
            }

            if (a[i][s] == 'W')
            {
                s--;
            }
        }

        if (f <= s)
        {
            x = i + 1, y = f + 1;
            int half = (s - f + 1) / 2;
            x += half;
            y += half;
            break;
        }
    }

    cout << x << " " << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}