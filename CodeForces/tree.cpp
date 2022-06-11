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
int lgN = 30;

class Node
{
public:
    int idx, w;
    vector<Node *> children;
    vector<pair<Node *, int>> up;
    Node(int _idx, int _w)
    {
        idx = _idx;
        w = _w;
    }
};

Node *root;

un_map<int, Node *> mp;

void solve()
{
    int n;
    cin >> n;

    int cnt = 1;
    root = new Node(cnt, 0);
    mp.insert({cnt, root});
    cnt++;

    int last = 0;
    while (n--)
    {
        int x, p, q;
        cin >> x >> p >> q;

        int r = p ^ last;
        int w = q ^ last;

        if (x == 1)
        {
            Node *nd = new Node(cnt, w);
            mp.insert({cnt, nd});
            mp[r]->children.phb(nd);
            cnt++;

            nd->up[0] = {mp[r], w};
            Node *cur = mp[r];
            for (int i = 1; i < lgN; i++)
            {
                if (i - 1 >= cur->up.size())
                {
                    break;
                }
                nd->up[i] = {cur->up[i - 1].first, cur->up[i - 1].second + cur->w};
                cur = cur->up[i - 1].first;
            }
        }
        else
        {
            last = 1;
        }
    }

    for (int i = 1; i < cnt; i++)
    {
        cout << "idx " << i << " : ";
        // for (int j = 0; j < mp[i]->children.size(); j++)
        // {
        //     cout << mp[i]->children[j]->idx << " ";
        // }

        // for (int j = 0; j < mp[i]->up.size(); j++)
        // {
        //     // cout << mp[i]->up[j].second << " ";
        // }

        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}