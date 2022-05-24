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

int f[26];

void solve()
{
    string str;
    cin >> str;

    string t;
    cin >> t;

    mem(f, 0);

    for (int i = 0; i < sz(str); i++)
    {
        int idx = str[i] - 'a';
        f[idx]++;
    }

    string ans = "";

    if (t == "abc" && f[0] != 0 && f[1] != 0 && f[2] != 0)
    {
        for (int i = 0; i < 26; i++)
        {
            char ch = (char)('a' + i);
            int cnt = f[i];

            if (i == 1)
            {
                ch = 'c';
                cnt = f[2];
            }
            else if (i == 2)
            {
                ch = 'b';
                cnt = f[1];
            }

            for (int j = 0; j < cnt; j++)
            {
                ans += ch;
            }
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            char ch = (char)('a' + i);
            for (int j = 0; j < f[i]; j++)
            {
                ans += ch;
            }
        }
    }

    cout << ans << "\n";
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