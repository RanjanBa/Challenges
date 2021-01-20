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
    int n, m; cin >> n >> m;
    vector<int> vec1(n);
    vector<int> vec2(m);

    ll sum1 = 0;
    rep(i,0,n,1) {
        cin >> vec1[i];
        sum1 += vec1[i];
    }

    ll sum2 = 0;
    rep(i,0,m,1) {
        cin >> vec2[i];
        sum2 += vec2[i];
    }

    sort(all(vec1));

    sort(all(vec2));
    reverse(all(vec2));

    int i = 0;

    while(sum1 <= sum2 && i < min(n, m)) {
        sum1 -= vec1[i];
        sum2 -= vec2[i];

        sum1 += vec2[i];
        sum2 += vec1[i];

        swap(vec1[i], vec2[i]);
        i++;
    }

    if(sum1 <= sum2) {
        i = -1;
    }

    cout << i << "\n";
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
