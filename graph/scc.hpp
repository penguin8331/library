#pragma once
#include "../template/template.hpp"

struct SCC {
    using Edge = int;
    using SGraph = vector<vector<Edge>>;

    // input
    SGraph G, rG;

    // result
    vector<vector<int>> scc;
    vector<int> cmp;
    SGraph dag;

    // constructor
    explicit SCC(int N) : G(N), rG(N) {}

    // add edge
    void addedge(int u, int v) {
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    // decomp
    vector<bool> seen;
    vector<int> vs, rvs;
    void dfs(int v) {
        seen[v] = true;
        for (auto e : G[v])
            if (!seen[e]) dfs(e);
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        seen[v] = true;
        cmp[v] = k;
        for (auto e : rG[v])
            if (!seen[e]) rdfs(e, k);
        rvs.push_back(v);
    }

    // reconstruct
    set<pair<int, int>> newEdges;
    void reconstruct() {
        int N = (int)G.size();
        int dV = (int)scc.size();
        dag.assign(dV, vector<Edge>());
        newEdges.clear();
        for (int i = 0; i < N; ++i) {
            int u = cmp[i];
            for (auto e : G[i]) {
                int v = cmp[e];
                if (u == v) continue;
                if (!newEdges.count({u, v})) {
                    dag[u].push_back(v);
                    newEdges.insert({u, v});
                }
            }
        }
    }

    // main
    void solve() {
        // first dfs
        int N = (int)G.size();
        seen.assign(N, false);
        vs.clear();
        for (int v = 0; v < N; ++v)
            if (!seen[v]) dfs(v);

        // back dfs
        int k = 0;
        scc.clear();
        cmp.assign(N, -1);
        seen.assign(N, false);
        for (int i = N - 1; i >= 0; --i) {
            if (!seen[vs[i]]) {
                rvs.clear();
                rdfs(vs[i], k++);
                scc.push_back(rvs);
            }
        }

        // reconstruct
        reconstruct();
    }
};