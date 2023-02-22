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

const int mxN = 1000;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int a[mxN];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans[3] = {-1, -1, -1};
    for (int i = 1; i < n - 1; i++)
    {
        int l = -1, r = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i])
            {
                l = j + 1;
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                r = j + 1;
                break;
            }
        }

        if (l != -1 && r != -1)
        {
            ans[0] = l, ans[1] = i + 1, ans[2] = r;
            break;
        }
    }

    if (ans[0] == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
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
        solve();
    }

    return 0;
}