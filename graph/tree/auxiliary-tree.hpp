#pragma once
#include "../../template/template.hpp"
#include "lca.hpp"

struct AuxiliaryTree : LCA {
    using super = LCA;

    vector<int> idx;
    vector<vector<int>> T;
    explicit AuxiliaryTree(const vector<vector<int>> &G, int r = 0)
        : super(G, r) {
        build(G, r);
    }

    void dfs(const vector<vector<int>> &G, int v, int p, int &pos) {
        idx[v] = pos++;
        for (int u : G[v])
            if (u != p) dfs(G, u, v, pos);
    }

    void build(const vector<vector<int>> &G, int r = 0) {
        int V = (int)G.size();
        idx.assign(V, 0);
        T.assign(V, vector<int>());
        int pos = 0;
        dfs(G, r, -1, pos);
    }

    void add_aux_edge(int u, int v) {
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }

    using super::get, super::depth;
    void query(vector<int> &vs) {
        assert(!vs.empty());
        sort(vs.begin(), vs.end(),
             [&](int a, int b) { return idx[a] < idx[b]; });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());

        int k = vs.size();
        stack<int> st;
        st.emplace(vs[0]);
        for (int i = 0; i + 1 < k; i++) {
            int w = get(vs[i], vs[i + 1]);
            if (w != vs[i]) {
                int l = st.top();
                st.pop();
                while (!st.empty() and depth[w] < depth[st.top()]) {
                    add_aux_edge(st.top(), l);
                    l = st.top();
                    st.pop();
                }
                if (st.empty() or st.top() != w) {
                    st.emplace(w);
                    vs.emplace_back(w);
                }
                add_aux_edge(w, l);
            }
            st.emplace(vs[i + 1]);
        }

        while (st.size() > 1) {
            int c = st.top();
            st.pop();
            add_aux_edge(st.top(), c);
        }
    }

    void clear(const vector<int> &ws) {
        for (int w : ws) T[w].clear();
    }
};
