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

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve()
{
    string str;
    cin >> str;

    int l = -1, r = -1;

    for (int i = 0; i < sz(str); i++)
    {
        if (str[i] == 'a')
        {
            l = r = i;
        }
    }

    bool ok = true;

    if (l == -1 || r == -1)
    {
        ok = false;
    }
    else
    {
        int i = 1;
        while (i < sz(str))
        {
            char ch = 'a' + i;

            bool found = false;
            if (l > 0 && ch == str[l - 1])
            {
                found = true;
                l--;
            }
            else if (r < sz(str) - 1 && ch == str[r + 1])
            {
                found = true;
                r++;
            }

            if (!found)
            {
                ok = false;
                break;
            }

            i++;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
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
