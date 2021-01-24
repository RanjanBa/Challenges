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

// ------ main function ------

const int mxN = 4005;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int dp[mxN], bo[mxN];

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    mem(dp, 0);
    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;

    rep(i, 1, n + 1, 1)
    {
        if (i > a && dp[i - a] > 0)
        {
            dp[i] = max(dp[i], dp[i - a] + 1);
        }

        if (i > b && dp[i - b] > 0)
        {
            dp[i] = max(dp[i], dp[i - b] + 1);
        }

        if (i > c && dp[i - c] > 0)
        {
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }

    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
