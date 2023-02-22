//TODO::

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

class Node
{
public:
    ll idx, w;
    vector<Node *> children;
    vector<pair<Node *, ll>> up;
    Node(ll _idx, ll _w)
    {
        idx = _idx;
        w = _w;
    }
};

Node *root;

un_map<ll, Node *> mp;

void solve()
{
    ll n;
    cin >> n;

    ll cnt = 1;
    root = new Node(cnt, 0);
    mp.insert({cnt, root});
    cnt++;

    ll last = 0;
    while (n--)
    {
        ll u, p, q;
        cin >> u >> p >> q;

        ll r = p ^ last;

        if (mp.find(r) == mp.end())
        {
            cout << "n : " << n << ", idx : " << r << ". Error in solution...\n";
            return;
        }

        if (u == 1)
        {
            ll w = q ^ last;
            Node *nd = new Node(cnt, w);
            mp.insert({cnt, nd});
            mp[r]->children.phb(nd);
            cnt++;

            nd->up.phb({mp[r], w});
            Node *cur = mp[r];
            ll i = 1;
            while (i - 1 < cur->up.size())
            {
                nd->up.phb({cur->up[i - 1].first, cur->up[i - 1].second + nd->up[i - 1].second});
                cur = cur->up[i - 1].first;
            }
        }
        else
        {
            ll x = q ^ last;

            cout << "r : " << r << ", x : " << x << "\n";

            for (ll i = 1; i < cnt; i++)
            {
                cout << "(" << i << "," << mp[i]->w << ") : ";

                for (ll j = 0; j < mp[i]->children.size(); j++)
                {
                    cout << mp[i]->children[j]->idx << " ";
                }

                //     // for (ll j = 0; j < mp[i]->up.size(); j++)
                //     // {
                //     //     cout << mp[i]->up[j].second << " ";
                //     // }

                cout << "\n";
            }

            Node *nd = mp[r];
            ll ans = 0;

            while (x >= nd->w && nd->up.size())
            {
                for (ll i = nd->up.size() - 1; i >= 0; i--)
                {
                    ll rem = x - nd->up[i].second;

                    if (rem >= 0)
                    {
                        ans += (1 << i);
                        x -= nd->up[i].second;
                        nd = nd->up[i].first;
                        break;
                    }
                }
            }

            if (nd == root)
            {
                ans++;
            }

            cout << ans << "\n";

            last = ans;
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