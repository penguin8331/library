#pragma once
#include "../../data-structure/lazy-segment-tree.hpp"
#include "../../data-structure/sparse-table.hpp"
#include "../../template/template.hpp"

// Euler Tour
template <class Node, class Monoid>
struct EulerTour {
    // main results
    vector<vector<int>> tree;
    vector<int> depth;
    vector<int> node;    // the node-number of i-th element of Euler-tour
    vector<int> vf, ve;  // the index of Euler-tour of node v
    vector<int> eid;     // the index of edge e (i*2 + (0: dir to leaf, 1: dir to root))
    const function<Node(Node, Node)> fm;
    const function<void(Node &, Monoid)> fa;
    const function<void(Monoid &, Monoid)> fl;

    // sub results
    SparseTable<pair<int, int>> st;  // depth (to find LCA)

    // segtree
    Lazy_SegTree<Node, Monoid> seg;

    // initialization
    EulerTour(const vector<vector<int>> &tree_,
              const function<Node(Node, Node)> fm_,
              const function<void(Node &, Monoid)> fa_,
              const function<void(Monoid &, Monoid)> fl_)
        : fm(fm_), fa(fa_), fl(fl_) {
        init(tree_);
    }

    void init(const vector<vector<int>> &tree_) {
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

    inline void update(int v, Monoid x) {
        seg.update(vf[v], ve[v], x);
    }

    inline Monoid get(int v) {
        return seg.get(0, vf[v]).first;
    }

    inline Monoid get(int u, int v) {
        int lca = LCA(u, v);
        return get(u) + get(v) - get(lca) * 2;
    }
};
