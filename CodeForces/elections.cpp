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

const int mxN = 50;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int a[mxN];

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int mx = max(a, max(b, c));

    int ans1 = 0, ans2 = 0, ans3 = 0;
    if (mx != a)
    {
        ans1 = mx - a + 1;
    }
    else if (mx == b || mx == c)
    {
        ans1 = 1;
    }

    if (mx != b)
    {
        ans2 = mx - b + 1;
    }
    else if (mx == a || mx == c)
    {
        ans2 = 1;
    }

    if (mx != c)
    {
        ans3 = mx - c + 1;
    }
    else if (mx == a || mx == b)
    {
        ans3 = 1;
    }

    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
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
