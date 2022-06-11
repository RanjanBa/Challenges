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

un_map<char, pair<int, pair<int, int>>> mp;

void solve()
{
    string q[3] = {"qwertyuiop",
                   "asdfghjkl;",
                   "zxcvbnm,./"};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < q[i].size(); j++)
        {
            mp.insert({q[i][j], {i, {j - 1, j + 1}}});
        }
    }

    char ch;
    cin >> ch;

    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        auto p = mp[s[i]];

        int idx = p.first;
        int l = p.second.first;
        int r = p.second.second;

        char x;
        if (ch == 'R')
        {
            x = q[idx][max(0, l)];
        }
        else
        {
            x = q[idx][min((int)q[idx].size() - 1, r)];
        }
        ans += x;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}