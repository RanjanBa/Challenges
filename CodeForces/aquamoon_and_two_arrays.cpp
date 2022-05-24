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

int a[mxN], b[mxN];

void solve()
{
    int n;
    cin >> n;

    int s1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        s1 += a[i];
    }

    int s2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        s2 += b[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cnt += a[i] - b[i];
        }
    }

    if (s1 != s2)
    {
        cout << "-1\n";
        return;
    }

    cout << cnt << "\n";

    if (cnt != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                int diff = a[i] - b[i];
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    if (a[j] < b[j])
                    {
                        int d = min(diff, b[j] - a[j]);
                        a[j] += d;
                        a[i] -= d;

                        diff -= d;

                        for (int k = 0; k < d; k++)
                        {
                            cout << (i + 1) << " " << (j + 1) << "\n";
                        }
                    }

                    if (diff == 0)
                    {
                        break;
                    }
                }
            }
        }
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