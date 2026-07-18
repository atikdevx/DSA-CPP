#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

void bellmanFord(int n, int source, vector<Edge> &edges)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (Edge edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
        {
            cout << "Negative cycle exists\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << source << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "Impossible\n";
        else
            cout << dist[i] << "\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    bellmanFord(n, source, edges);

    return 0;
}