#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

void dijkstra(int source,
              vector<vector<pair<int, int>>> &adj,
              vector<int> &dist)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (distance > dist[u])
            continue;

        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);

    dijkstra(source, adj, dist);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }

    cout << "\n";

    return 0;
}
/*
Section B 24
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

void dijkstra(vector<int> &centers,
              vector<vector<pair<int, long long>>> &adj,
              vector<long long> &dist)
{
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    // All emergency centers are sources
    for (int center : centers)
    {
        dist[center] = 0;
        pq.push({0, center});
    }

    while (!pq.empty())
    {
        long long distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (distance > dist[u])
            continue;

        for (auto e : adj[u])
        {
            int v = e.first;
            long long w = e.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> centers(k);

    for (int i = 0; i < k; i++)
    {
        cin >> centers[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long weight;

        cin >> u >> v >> weight;

        // Reverse the original directed edge u -> v
        adj[v].push_back({u, weight});
    }

    vector<long long> dist(n + 1, LLONG_MAX);

    dijkstra(centers, adj, dist);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
    */