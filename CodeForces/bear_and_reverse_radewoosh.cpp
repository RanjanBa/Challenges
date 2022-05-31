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

const int mxN = 50;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int a[mxN], t[mxN];

void solve()
{
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    int l = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += t[i];

        l += max(0, a[i] - c * x);
    }

    int r = 0;
    x = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        x += t[i];

        r += max(0, a[i] - c * x);
    }

    if (l > r)
    {
        cout << "Limak\n";
    }
    else if (r > l)
    {
        cout << "Radewoosh\n";
    }
    else
    {
        cout << "Tie\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}