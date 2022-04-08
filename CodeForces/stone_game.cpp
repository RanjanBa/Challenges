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

const int mxN = 105;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int a[mxN];

void solve()
{
    int n;
    cin >> n;

    mem(a, 0);

    int l, lowestIndex;
    int g, greatestIndex;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (i == 0)
        {
            l = a[i];
            g = a[i];
            lowestIndex = 0;
            greatestIndex = 0;
        }
        else
        {
            if (a[i] < l)
            {
                l = a[i];
                lowestIndex = i;
            }

            if (a[i] > g)
            {
                g = a[i];
                greatestIndex = i;
            }
        }
    }

    int ans = max(lowestIndex + 1, greatestIndex + 1);
    
    ans = min(ans, max(n - lowestIndex, n - greatestIndex));

    ans = min(ans, lowestIndex + 1 + n - greatestIndex);

    ans = min(ans, n - lowestIndex + greatestIndex + 1);

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
