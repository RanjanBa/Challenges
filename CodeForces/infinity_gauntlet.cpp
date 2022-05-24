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

int f[6];

void solve()
{
    mem(f, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string col;
        cin >> col;

        if (col == "purple")
        {
            f[0] = 1;
        }
        else if (col == "green")
        {
            f[1] = 1;
        }
        else if (col == "blue")
        {
            f[2] = 1;
        }
        else if (col == "orange")
        {
            f[3] = 1;
        }
        else if (col == "red")
        {
            f[4] = 1;
        }
        else if (col == "yellow")
        {
            f[5] = 1;
        }
    }

    int cnt = 0;
    vector<string> vec;
    for (int i = 0; i < 6; i++)
    {
        if (f[i] == 0)
        {
            cnt++;
            if (i == 0)
            {
                vec.phb("Power");
            }
            else if (i == 1)
            {
                vec.phb("Time");
            }
            else if (i == 2)
            {
                vec.phb("Space");
            }
            else if (i == 3)
            {
                vec.phb("Soul");
            }
            else if (i == 4)
            {
                vec.phb("Reality");
            }
            else
            {
                vec.phb("Mind");
            }
        }
    }

    cout << cnt << "\n";
    if (cnt >= 0)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}