#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define phb push_back
#define ppb pop_back
#define arr array
#define FOR(i, x) for(int i = 0; i < x; i++)
#define FORS(i, s, x) for(int i = s; i < x; i++)
#define FORR(i, x) for(int i = x - 1; i >= 0; i--)
#define FORV(v, li) for(auto v : li)
#define SZ(v) (int)v.size()
#define all(v) v.begin() , v.end()
#define un_set unordered_set
#define un_map unordered_map
#define mem(li,v) memset(li, v, sizeof(li))
#define INF 1e9
#define INFL 1e18

using namespace std;

template<typename T>
inline void debug(vector<T> li) {
    FORV(v, li) {
        cout << v << " ";
    }
    
    cout << endl;
}

template<typename T>
inline void debug(vector<vector<T>> li) {
    FORV(v1, li) {
        FORV(v2, v1) {
            cout << v2 << " ";
        }
        
        cout << endl;
    }
}

const int mxN = 2e5;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void solve() {
    int x;
    cin >> x;

    if(x < 10) {
        cout << x << "\n";
        return;
    }

    if(x > 45) {
        cout << -1 << "\n";
        return;
    }

    // if(x >= 36) {
    //     string str;
    //     x = 45 - x;
    //     FORS(i, 1, 10) {
    //         if(x == i) continue;

    //         str += to_string(i);
    //     }
    // }

    int s = 0;
    string str;
    for (int i = 9; i > 0; i--)
    {
        if(i + s > x) continue;

        s += i;
        str += to_string(i);
    }

    reverse(str.begin(), str.end());

    cout << str << "\n";
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