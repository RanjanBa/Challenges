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
const char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<char> vec;

    for (int i = 0; i < n; i++)
    {
        vec.phb(str[i]);
    }

    int idx = 1;
    while (idx < vec.size())
    {
        bool isFirst = false;
        for (int i = 0; i < 6; i++)
        {
            if (vec[idx - 1] == vowels[i])
            {
                isFirst = true;
                break;
            }
        }

        bool isSecond = false;
        for (int i = 0; i < 6; i++)
        {
            if (vec[idx] == vowels[i])
            {
                isSecond = true;
                break;
            }
        }

        if (isFirst && isSecond)
        {
            vec.erase(vec.begin() + idx, vec.begin() + idx + 1);
            continue;
        }

        idx++;
    }

    str = "";

    for (int i = 0; i < vec.size(); i++)
    {
        str += vec[i];
    }

    cout << str << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}