#pragma once
#include "../../data-structure/segment-tree.hpp"
#include "../../data-structure/sparse-table.hpp"
#include "../../template/template.hpp"

struct Edge {
    int next;
    long long cost;
    int idx;
};
struct EulerTour {
    using pli = pair<long long, int>;
    vector<int> edge;
    vector<int> node;
    vector<int> vf, ve;
    vector<int> ef, ee;
    vector<int> depth;
    vector<vector<Edge>> tree;
    SparseTable<pair<int, int>> st;
    SegTree<pli> seg;
    const function<pli(pli, pli)> fm = [](pli a, pli b) { return pli{a.first * a.second + b.first * b.second, 1}; };
    EulerTour(const vector<vector<Edge>>& tree_) {
        init(tree_);
    }
    void init(const vector<vector<Edge>>& tree_) {
        tree = tree_;
        int V = (int)tree.size();
        depth.resize(V * 2 - 1);
        edge.resize(V * 2 - 2);
        node.resize(V * 2 - 1);
        vf.resize(V);
        ve.resize(V);
        ef.resize(V - 1);
        ee.resize(V - 1);
        seg.init((V - 1) * 2, fm, pli({0, 0}));
        int k = 0;
        dfs(0, -1, 0, k);
        vector<pair<int, int>> tmp((int)depth.size());
        for (int i = 0; i < (int)depth.size(); i++) {
            tmp[i] = {depth[i], i};
        }
        st.init(tmp);
        seg.build();
    }
    void dfs(int now, int prev, int dep, int& ord) {
        node[ord] = now;
        depth[ord] = dep;
        vf[now] = ve[now] = ord;
        ord++;
        for (const auto& [next, cost, idx] : tree[now]) {
            if (next != prev) {
                seg.set(ord - 1, {cost, 1});
                edge[ord - 1] = idx;
                ef[idx] = ord - 1;
                dfs(next, now, dep + 1, ord);
                node[ord] = now;
                depth[ord] = dep;
                ve[next] = ord;
                ee[idx] = ord - 1;
                seg.set(ord - 1, {cost, -1});
                edge[ord - 1] = idx;
                ord++;
            }
        }
    }
    inline int LCA(int u, int v) {
        int a = vf[u], b = vf[v];
        if (a > b) swap(a, b);
        return node[st.get(a, b + 1).second];
    }
    inline void update(int idx, int x) {
        seg.update(ef[idx], {x, 1});
        seg.update(ee[idx], {x, -1});
    }
    inline long long get(int v) {
        return seg.get(0, vf[v]).first;
    }
    inline long long get(int u, int v) {
        int lca = LCA(u, v);
        return get(u) + get(v) - get(lca) * 2;
    }
};