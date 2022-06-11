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

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int sg[2 * mxN];
int a[mxN];
int n, q;

void update(int idx, int v)
{
    int i = n + idx;

    sg[i] = sg[i] - a[idx] + v;

    while (i > 0)
    {
        sg[i >> 1] = sg[i >> 1] - a[idx] + v;
        i = i >> 1;
    }

    a[idx] = v;
}

int query(int l, int r)
{
    ll res = 0;

    r++;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res += a[l];
            l++;
        }

        if (r & 1)
        {
            r--;
            res += a[r];
        }
    }

    return res;
}

void solve()
{
    mem(sg, 0);

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sg[n + i] = a[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        sg[i] = sg[2 * i] + sg[2 * i + 1];
    }

    for (int i = 1; i < 2 * n; i++)
    {
        cout << sg[i] << " ";
    }

    cout << "\n";

    while (q--)
    {
        int k, x, y;
        cin >> k >> x >> y;

        if (k == 1)
        {
            x--;
            update(x, y);
        }
        else
        {
            x--, y--;
            cout << query(x, y) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}