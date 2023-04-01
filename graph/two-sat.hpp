#pragma once
#include "../template/template.hpp"
#include "scc.hpp"

struct TwoSat {
    int N;
    SCC scc;
    TwoSat(int n) : N(n), scc(2 * N) {}

    void add(int i, bool f, int j, bool g) {
        scc.addedge(i + (f ? N : 0), j + (g ? 0 : N));
        scc.addedge(j + (g ? N : 0), i + (f ? 0 : N));
    }
    void add_eq(int i, int j) {
        add(i, true, j, false);
        add(i, false, j, true);
    }
    void add_neq(int i, int j) {
        add(i, true, j, true);
        add(i, false, j, false);
    }
    void add_true(int i) {
        scc.addedge(i + N, i);
    }
    void add_false(int i) {
        scc.addedge(i, i + N);
    }
    vector<bool> solve() {
        scc.solve();
        vector<bool> ans(N);
        for (int i = 0; i < N; i++) {
            if (scc.cmp[i] == scc.cmp[i + N]) {
                return vector<bool>();
            }
            if (scc.cmp[i] > scc.cmp[i + N]) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        return ans;
    }
};