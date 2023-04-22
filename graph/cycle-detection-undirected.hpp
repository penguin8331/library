#pragma once
#include "../template/template.hpp"

void solve(int N, int M, vector<pair<int, int>> edges, vector<vector<pair<int, int>>> G, vector<int>& V, vector<int>& E) {
    // dfs tree
    vector<bool> used_e(M);
    vector<pair<int, int>> par(N, {-1, -1});  // (vid, eid)
    vector<int> dep(N, -1);
    auto dfs = [&](auto& dfs, int v, int d) -> void {
        assert(dep[v] == -1);
        dep[v] = d;
        for (auto&& [eid, to] : G[v]) {
            if (dep[to] != -1) continue;
            used_e[eid] = 1;
            par[to] = {v, eid};
            dfs(dfs, to, d + 1);
        }
    };

    for (int v = 0; v < N; ++v) {
        if (dep[v] == -1) dfs(dfs, v, 0);
    }

    auto check = [&](vector<int> V, vector<int> E) -> bool {
        int L = V.size();
        assert(L >= 1);
        vector<int> used_v(N), used_e(M);
        for (auto&& v : V) {
            if (used_v[v]) return false;
            used_v[v] = 1;
        }
        for (auto&& e : E) {
            if (used_e[e]) return false;
            used_e[e] = 1;
        }
        for (int i = 0; i < L; ++i) {
            auto [a, b] = edges[E[i]];
            int j = (i + 1 == L ? 0 : i + 1);
            bool ok = 0;
            if (V[i] == a && V[j] == b) ok = 1;
            if (V[i] == b && V[j] == a) ok = 1;
            if (!ok) return false;
        }
        return true;
    };

    for (int eid = 0; eid < M; ++eid) {
        if (used_e[eid]) continue;
        auto [a, b] = edges[eid];
        if (dep[a] > dep[b]) swap(a, b);
        assert(dep[a] <= dep[b]);

        // 後退辺 e から、サイクルが出来る
        V = {b};
        while (V.back() != a) {
            auto [v, e] = par[V.back()];
            V.push_back(v);
            E.push_back(e);
        }
        E.push_back(eid);
        assert(check(V, E));
        return;
    }
    return;
}