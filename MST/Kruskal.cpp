#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return false; // cycle

        parent[v] = u; // connect one leader with another leader

        return true;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<edge> edges;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), comp);

    DSU dsu(N);

    long long mst_cost = 0;
    vector<edge> mst_edges;

    for (edge e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            mst_cost += e.w;
            mst_edges.push_back(e);

            if (mst_edges.size() == N - 1)
                break;
        }
    }

    if (mst_edges.size() != N - 1)
    {
        cout << "Not possible" << endl;
    }
    else
    {
        cout << "Minimum cost: " << mst_cost << endl;

        for (edge e : mst_edges)
        {
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }

    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compEdge(Edge a, Edge b) {
    return a.w < b.w;
}

struct Planet {
    int id, x, y, z;
};

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int para = find(a);
        int parb = find(b);

        if (para == parb) return false;

        if (sz[para] < sz[parb]) swap(para, parb);

        parent[parb] = para;
        sz[para] += sz[parb];

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Planet> planets(N);

    for (int i = 0; i < N; i++) {
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
        planets[i].id = i + 1;
    }

    vector<Edge> edges;

    // Sort by x
    sort(planets.begin(), planets.end(), [](Planet a, Planet b) {
        return a.x < b.x;
    });

    for (int i = 0; i < N - 1; i++) {
        edges.push_back({
            planets[i].id,
            planets[i + 1].id,
            abs(planets[i].x - planets[i + 1].x)
        });
    }

    // Sort by y
    sort(planets.begin(), planets.end(), [](Planet a, Planet b) {
        return a.y < b.y;
    });

    for (int i = 0; i < N - 1; i++) {
        edges.push_back({
            planets[i].id,
            planets[i + 1].id,
            abs(planets[i].y - planets[i + 1].y)
        });
    }

    // Sort by z
    sort(planets.begin(), planets.end(), [](Planet a, Planet b) {
        return a.z < b.z;
    });

    for (int i = 0; i < N - 1; i++) {
        edges.push_back({
            planets[i].id,
            planets[i + 1].id,
            abs(planets[i].z - planets[i + 1].z)
        });
    }

    sort(edges.begin(), edges.end(), compEdge);

    DSU d(N);

    long long mst_cost = 0;

    for (Edge e : edges) {
        if (d.unite(e.u, e.v)) {
            mst_cost += e.w;
        }
    }

    cout << mst_cost << endl;

    return 0;
}*/