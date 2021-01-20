#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define rep(i,s,x,inc) for(int i = s; i < x; i+=inc)
#define repr(i,e,x,dec) for(int i = x - 1; i >= e; i-=dec)
#define repv(v, li) for(auto v : li)
#define sz(li) (int)li.size()
#define all(v) v.begin() , v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li,v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
    repv(v, li) {
        cout << v << " ";
    }
    
    cout << "\n";
}

template<typename T>
inline void debug(vector<vector<T>> li) {
    repv(v1, li) {
        repv(v2, v1) {
            cout << v2 << " ";
        }
        
        cout << "\n";
    }
}

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> vec(n);

    rep(i,0,n,1) {
        cin >> vec[i];
    }

    sort(all(vec));

    ll sum1 = 0, sum2 = 0, res = 0;

    while(sz(vec) && sum1 + vec.back() < k) {
        sum1 += vec.back();
        res++;
        vec.ppb();
    }

    ll diff = k - sum1;
    ll idx = lower_bound(all(vec), diff) - vec.begin();
    // cout << "te: " << diff << " " << idx << "\n";

    if(idx < sz(vec)) {
        sum1 += vec[idx];
        vec.erase(vec.begin() + idx);
        res++;
    }

    while(sz(vec) && sum2 + vec.back() < k) {
        sum2 += vec.back();
        res++;
        vec.ppb();
    }

    diff = k - sum2;
    idx = lower_bound(all(vec), diff) - vec.begin();

    if(idx < sz(vec)) {
        sum2 += vec[idx];
        vec.erase(vec.begin() + idx);
        res++;
    }

    // cout << sum1 << " " << sum2 << "\n";
    if(sum1 < k || sum2 < k) {
        cout << -1 << "\n";
    } else {
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
