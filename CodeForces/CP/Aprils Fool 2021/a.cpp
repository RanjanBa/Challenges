#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORR(i, x) for (int i = x - 1; i >= 0; i--)
#define FORV(v, li) for (auto v : li)

using namespace std;

template <typename T>
inline void debug(vector<T> li)
{
    FORV(v, li)
    {
        cout << v << " ";
    }

    cout << endl;
}

template <typename T>
inline void debug(vector<vector<T>> li)
{
    FORV(v1, li)
    {
        FORV(v2, v1)
        {
            cout << v2 << " ";
        }

        cout << endl;
    }
}

void solve()
{
    string str;
    while (true)
    {
        getline(cin, str);

        if (str.size() == 0)
        {
            break;
        }

        cout << "No"
             << "\n";
    }

    cout << res << endl;
}

int main()
{
    solve();

    return 0;
}
