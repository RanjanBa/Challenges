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
    int n;
    cin >> n;

    vector<ll> even, odd;

    rep(i, 0, n, 1)
    {
        ll a;
        cin >> a;

        if (a & 1)
        {
            odd.phb(a);
        }
        else
        {
            even.phb(a);
        }
    }

    sort(all(even));
    reverse(all(even));
    sort(all(odd));
    reverse(all(odd));

    ll ev = 0, od = 0;
    int k = 0, l = 0;
    rep(i, 0, n, 1)
    {
        if (k < sz(even) && l < sz(odd))
        {
            if (i & 1)
            {
                if (odd[l] >= even[k])
                {
                    od += odd[l];
                    l++;
                }
                else
                {
                    k++;
                }
            }
            else
            {
                if (even[k] >= odd[l])
                {
                    ev += even[k];
                    k++;
                }
                else
                {
                    l++;
                }
            }
        }
        else
        {
            if (i & 1)
            {
                if (l < sz(odd))
                {
                    od += odd[l];
                    l++;
                }
                else
                {
                    k++;
                }
            }
            else
            {
                if (k < sz(even))
                {
                    ev += even[k];
                    k++;
                }
                else
                {
                    l++;
                }
            }
        }
    }

    if (ev == od)
    {
        cout << "Tie\n";
    }
    else if (ev > od)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
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
