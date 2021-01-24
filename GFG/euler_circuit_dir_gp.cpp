// { Driver Code Starts
#include <bits/stdc++.h>
// #include <list>
#define CHARS 26
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    int *in;

public:
    Graph(int V);
    ~Graph()
    {
        delete[] adj;
        delete[] in;
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        (in[w])++;
    }
    bool isEulerianCycle();
    bool isSC();
    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
        in[i] = 0;
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        Graph g(V);
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }
        if (g.isEulerianCycle())
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends

/*Complete the function below*/
bool Graph::isEulerianCycle()
{
    int indeg[V], outdeg[V];

    memset(indeg, 0, sizeof(indeg));
    memset(outdeg, 0, sizeof(outdeg));

    int start = -1;

    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            start = i;
            outdeg[i]++;
            indeg[v]++;
        }
    }

    int vis[V];
    memset(vis, 0, sizeof(vis));

    queue<int> qu;
    qu.push(start);
    vis[start] = 1;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();

        for (int v : adj[u])
        {
            if (vis[v])
                continue;

            vis[v] = 1;
            qu.push(v);
        }
    }

    for (int i = 0; i < V; i++)
    {
        int diff = indeg[i] - outdeg[i];
        if (vis[i] == 0 || diff)
        {
            if (indeg[i] || outdeg[i])
            {
                return false;
            }
        }
    }

    return true;
}