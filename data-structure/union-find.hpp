#pragma once
#include "../template/template.hpp"

struct UnionFind {
    vector<int> par;

    UnionFind() {}
    explicit UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }

    vector<vector<int>> groups() {
        map<int, vector<int>> root_buf;
        for (int i = 0; i < (int)par.size(); ++i) {
            int r = root(i);
            root_buf[r].push_back(i);
        }
        vector<vector<int>> res;
        for (const auto& i : root_buf) {
            res.push_back(i.second);
        }
        return res;
    }
};