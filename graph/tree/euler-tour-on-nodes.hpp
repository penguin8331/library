#pragma once
#include "../../data-structure/lazy-segment-tree.hpp"
#include "../../data-structure/sparse-table.hpp"
#include "../../template/template.hpp"

struct EulerTour {
    using Graph = vector<vector<int>>;
    using Node = pair<long long, int>;
    const function<Node(Node, Node)> fm = [](Node a, Node b) { return Node(a.first + b.first, a.second + b.second); };
    const function<void(Node &, long long)> fa = [](Node &a, long long d) { a.first += d * a.second; };
    const function<void(long long &, long long)> fl = [](long long &d, long long e) { d += e; };

    // main results
    Graph tree;
    vector<int> depth;
    vector<int> node;    // the node-number of i-th element of Euler-tour
    vector<int> vf, ve;  // the index of Euler-tour of node v
    vector<int> eid;     // the index of edge e (i*2 + (0: dir to leaf, 1: dir to root))

    // sub results
    SparseTable<pair<int, int>> st;  // depth (to find LCA)

    // segtree
    Lazy_SegTree<Node, long long> seg;

    // initialization
    EulerTour(const Graph &tree_) { init(tree_); }
    void init(const Graph &tree_) {
        tree = tree_;
        int V = (int)tree.size();
        depth.resize(V * 2 - 1);
        node.resize(V * 2 - 1);
        vf.resize(V);
        ve.resize(V);
        eid.resize((V - 1) * 2);
        seg.init((V - 1) * 2, fm, fa, fl, Node(0, 0), 0);
        int k = 0;
        dfs(0, -1, 0, k);
        vector<pair<int, int>> tmp(int(depth.size()));
        for (int i = 0; i < int(depth.size()); i++) {
            tmp[i] = {depth[i], i};
        }
        st.init(tmp);
        seg.build();
    }

    void dfs(int v, int par, int dep, int &ord) {
        node[ord] = v;
        depth[ord] = dep;
        vf[v] = ve[v] = ord;
        ++ord;
        for (auto e : tree[v]) {
            if (e == par) continue;
            seg.set(ord - 1, Node(0, 1));
            dfs(e, v, dep + 1, ord);
            node[ord] = v;
            depth[ord] = dep;
            ve[v] = ord;
            seg.set(ord - 1, Node(0, -1));
            ++ord;
        }
    }

    inline int LCA(int u, int v) {
        int a = vf[u], b = vf[v];
        if (a > b) swap(a, b);
        return node[st.get(a, b + 1).second];
    }

    inline void update(int v, long long x) {
        seg.update(vf[v], ve[v], x);
    }

    inline long long get(int v) {
        return seg.get(0, vf[v]).first;
    }

    inline long long get(int u, int v) {
        int lca = LCA(u, v);
        return get(u) + get(v) - get(lca) * 2;
    }
};