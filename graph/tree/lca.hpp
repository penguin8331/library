#pragma once
#include "../template/template.hpp"

struct LCA {
    vector<vector<int>> parent;
    vector<int> depth;
    LCA() {}
    explicit LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }
    void init(const vector<vector<int>>& G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while ((1 << h) < V) ++h;
        parent.assign(h, vector<int>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (int i = 0; i + 1 < (int)parent.size(); ++i)
            for (int v = 0; v < V; ++v)
                if (parent[i][v] != -1)
                    parent[i + 1][v] = parent[i][parent[i][v]];
    }
    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v])
            if (e != p) dfs(G, e, v, d + 1);
    }
    int after(int u, int k) {
        for (int i = 0; i < (int)parent.size(); i++) {
            if (k & (1 << i)) {
                u = parent[i][u];
            }
        }
        return u;
    }
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        v = after(v, depth[v] - depth[u]);
        if (u == v) return u;
        for (int i = (int)parent.size() - 1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[get(u, v)];
    }
    bool is_on_path(int u, int v, int a) {
        return dist(u, a) + dist(a, v) == dist(u, v);
    }
};