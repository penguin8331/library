#pragma once
#include "../template/template.hpp"

struct Edge {
    int to;
    int cost;
};
template <typename T>
pair<T, int> dfs(const vector<vector<Edge>> &G, int u, int par) {
    pair<T, int> ret = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs<T>(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
template <typename T>
T tree_diameter(const vector<vector<Edge>> &G) {
    pair<T, int> p = dfs<T>(G, 0, -1);
    pair<T, int> q = dfs<T>(G, p.second, -1);
    return q.first;
}