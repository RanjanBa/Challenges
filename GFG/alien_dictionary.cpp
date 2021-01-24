#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++)
            order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i])
                f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

// const int INF = 1e9;
// int vis[26], exist[26];
// vector<int> adj[26];

// void dfs(int u, stack<int> &st)
// {
//     vis[u] = 1;

//     for (int v : adj[u])
//     {
//         if (vis[v])
//             continue;
//         dfs(v, st);
//     }

//     st.push(u);
// }

// stack<int> topologicalSort(int s)
// {
//     stack<int> st;

//     for (int i = 0; i < 26; i++)
//     {
//         if (vis[i] || !exist[i])
//             continue;

//         dfs(s, st);
//     }

//     return st;
// }

// string findOrder(string dict[], int n, int k)
// {
//     memset(exist, 0, sizeof(exist));

//     for (int i = 0; i < 26; i++)
//     {
//         adj[i].clear();
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         int min_len = min(dict[i].size(), dict[i + 1].size());

//         for (int j = 0; j < min_len; j++)
//         {
//             int f = dict[i][j] - 'a', s = dict[i + 1][j] - 'a';
//             if (f != s)
//             {
//                 adj[f].push_back(s);
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < dict[i].size(); j++)
//         {
//             int k = dict[i][j] - 'a';
//             exist[k] = 1;
//         }
//     }

//     int start = dict[0][0] - 'a';
//     stack<int> st = topologicalSort(start);

//     string res;
//     memset(vis, 0, sizeof(vis));

//     while (st.size())
//     {
//         int k = st.top();
//         res += (char)('a' + k);
//         vis[k] = 1;
//         st.pop();
//     }

//     cout << res << "\n";
//     for (int i = 0; i < 26; i++)
//     {
//         if (exist[i] && !vis[i])
//         {
//             res += (char)('a' + i);
//         }
//     }

//     cout << res << "\n";
//     return res;
// }

void DFSRec(vector<int> adj[], int u, stack<int> &st, vector<bool> &visited)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (visited[v] == false)
        {
            DFSRec(adj, v, st, visited);
        }
    }

    st.push(u);
}

string topologicalSort(vector<int> adj[], int V)
{
    stack<int> st;
    vector<bool> visited(V, false);

    for (int v = 0; v < V; v++)
    {
        if (adj[v].size())
        {
            for (auto u : adj[v])
            {
                if (visited[u] == false)
                {
                    DFSRec(adj, u, st, visited);
                }
            }
        }
    }

    string res;
    while (st.empty() == false)
    {
        res += st.top() + 'a';
        ;

        st.pop();
    }
    cout << res << "\n";
    return res;
}

string findOrder(string words[], int N, int K)
{
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++)
    {
        string word1 = words[i];
        string word2 = words[i + 1];

        for (int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            if (word1[j] != word2[j])
            {
                int index1 = word1[j] - 'a';
                int index2 = word2[j] - 'a';

                adj[index1].push_back(index2);

                break;
            }
        }
    }

    return topologicalSort(adj, K);
}