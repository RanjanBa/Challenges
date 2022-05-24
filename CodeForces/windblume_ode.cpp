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

const int mxN = 100;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int a[mxN];

bool isComposite(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }

    return false;
}

void solve()
{
    int n;
    cin >> n;

    int acc = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        acc += a[i];
    }

    vector<int> vec;
    int ans = n;

    if (acc <= 3)
    {
        ans = 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            vec.phb(i + 1);
        }
    }

    if (!isComposite(acc))
    {
        for (int i = 0; i < n; i++)
        {
            if (acc % 2 == 1)
            {
                acc -= a[i];
                if (isComposite(acc))
                {
                    ans = n - 1;
                    vec.erase(vec.begin() + i, vec.begin() + i + 1);
                    break;
                }

                acc += a[i];
            }
        }
    }

    cout << ans << "\n";

    if (ans != 0)
    {
        debug(vec);
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