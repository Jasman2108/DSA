#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u=0, int _v=0, int _w=0) : u(_u), v(_v), w(_w) {}
};

struct DSU {
    vector<int> parent, rankv;
    DSU(int n=0) : parent(n), rankv(n,0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

struct Graph {
    int n;
    bool directed;
    vector<vector<pair<int,int>>> adj;
    vector<Edge> edges;

    Graph(int n=0, bool directed=false) : n(n), directed(directed) {
        adj.assign(n, {});
    }

    void addEdge(int u, int v, int w=1) {
        adj[u].push_back({v, w});
        edges.emplace_back(u, v, w);
        if (!directed) {
            adj[v].push_back({u, w});
            if (u > v) { edges.pop_back(); edges.emplace_back(v, u, w); }
        }
    }

    vector<int> BFS(int s) {
        vector<int> vis(n,0), order;
        queue<int> q;
        vis[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (auto &p : adj[u]) {
                int v = p.first;
                if (!vis[v]) { vis[v] = 1; q.push(v); }
            }
        }
        return order;
    }

    void dfsUtil(int u, vector<int>& vis, vector<int>& order) {
        vis[u] = 1;
        order.push_back(u);
        for (auto &p : adj[u]) {
            int v = p.first;
            if (!vis[v]) dfsUtil(v, vis, order);
        }
    }
    vector<int> DFS(int s) {
        vector<int> vis(n,0), order;
        dfsUtil(s, vis, order);
        return order;
    }

    pair<long long, vector<Edge>> KruskalMST() {
        vector<Edge> es = edges, res;
        sort(es.begin(), es.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });
        DSU dsu(n);
        long long total = 0;
        for (auto &e : es) {
            if (dsu.unite(e.u, e.v)) {
                res.push_back(e);
                total += e.w;
                if ((int)res.size() == n-1) break;
            }
        }
        return make_pair(total, res);
    }

    pair<long long, vector<Edge>> PrimMST(int s=0) {
        vector<int> used(n,0);
        vector<Edge> mst;
        typedef tuple<int,int,int> T;
        priority_queue<T, vector<T>, greater<T>> pq;
        used[s] = 1;
        for (auto &p : adj[s]) pq.emplace(p.second, s, p.first);
        long long total = 0;
        while (!pq.empty()) {
            T t = pq.top(); pq.pop();
            int w = get<0>(t);
            int u = get<1>(t);
            int v = get<2>(t);
            if (used[v]) continue;
            used[v] = 1;
            mst.emplace_back(u, v, w);
            total += w;
            for (auto &p : adj[v]) {
                if (!used[p.first]) pq.emplace(p.second, v, p.first);
            }
        }
        return make_pair(total, mst);
    }

    pair<vector<long long>, vector<int>> Dijkstra(int s) {
        const long long INF = (long long)1e18;
        vector<long long> dist(n, INF);
        vector<int> parent(n, -1);
        dist[s] = 0;
        typedef pair<long long,int> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            P pr = pq.top(); pq.pop();
            long long d = pr.first;
            int u = pr.second;
            if (d != dist[u]) continue;
            for (auto &p : adj[u]) {
                int v = p.first;
                long long w = p.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        return make_pair(dist, parent);
    }
};

void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    Graph g(5, false);
    g.addEdge(0,1,1);
    g.addEdge(0,3,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,3);
    g.addEdge(2,4,2);
    g.addEdge(3,4,5);

    cout << "BFS: ";
    printVec(g.BFS(0));

    cout << "DFS: ";
    printVec(g.DFS(0));

    pair<long long, vector<Edge>> kres = g.KruskalMST();
    long long kw = kres.first;
    vector<Edge> ke = kres.second;
    cout << "Kruskal MST weight: " << kw << "\n";

    pair<long long, vector<Edge>> pres = g.PrimMST(0);
    long long pw = pres.first;
    vector<Edge> pe = pres.second;
    cout << "Prim MST weight: " << pw << "\n";

    pair<vector<long long>, vector<int>> dres = g.Dijkstra(0);
    vector<long long> dist = dres.first;
    vector<int> parent = dres.second;
    cout << "Dijkstra distances:\n";
    for (int i = 0; i < 5; i++) cout << i << ": " << dist[i] << "\n";

    return 0;
}
