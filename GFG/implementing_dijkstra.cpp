// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>, int, int);

void printSolution(vector<int> dist, int n)
{

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}
int main()
{
    int t;
    int V;
    cin >> t;
    while (t--)
    {
        cin >> V;

        vector<vector<int>> g(V);

        for (int i = 0; i < V; i++)
        {
            vector<int> temp(V);
            g[i] = temp;
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cin >> g[i][j];
            }
        }

        int s;
        cin >> s;

        vector<int> res = dijkstra(g, s, V);
        printSolution(res, V);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector<int> dijkstra(vector<vector<int>> g, int src, int V)
{
    int n = g.size();

    vector<int> dist(n, 1e9);

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (pq.size())
    {
        auto t = pq.top();
        int d = t[0], u = t[1];
        pq.pop();

        for (int v : g[u])
        {
            cout << "v: " << v << "\n";
            int nd = d + 1;

            if (nd < dist[v])
            {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return dist;
}