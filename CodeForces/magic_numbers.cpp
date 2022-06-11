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

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    string a = "1", b = "14", c = "144";

    bool ok = true;
    int idx = 0;

    while (idx < n && ok)
    {
        if (idx + 3 <= n)
        {
            string p = s.substr(idx, 3);

            if (p == c)
            {
                idx += 3;
                continue;
            }
        }

        if (idx + 2 <= n)
        {
            string p = s.substr(idx, 2);

            if (p == b)
            {
                idx += 2;
                continue;
            }
        }

        if (idx + 1 <= n)
        {
            string p = s.substr(idx, 1);

            if (p == a)
            {
                idx += 1;
                continue;
            }
        }

        ok = false;
    }

    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}