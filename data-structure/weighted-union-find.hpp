#pragma once
#include "../template/template.hpp"

template <class T>
struct WeightedUnionFind {
    // core member
    vector<int> par;
    vector<T> weight;

    // constructor
    WeightedUnionFind() {}
    WeightedUnionFind(int N, T zero = 0) : par(N, -1), weight(N, zero) {}
    void init(int N, T zero = 0) {
        par.assign(N, -1);
        weight.assign(N, zero);
    }

    // core methods
    int root(int x) {
        if (par[x] < 0)
            return x;
        else {
            int r = root(par[x]);
            weight[x] += weight[par[x]];
            return par[x] = r;
        }
    }
    bool issame(int x, int y) { return root(x) == root(y); }

    // v[y] - v[x] = w
    bool unite(int x, int y, T w) {
        w += get_weight(x), w -= get_weight(y);
        x = root(x), y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y), w = -w;  // merge technique
        par[x] += par[y];
        par[y] = x;
        weight[y] = w;
        return true;
    }

    int size(int x) { return -par[root(x)]; }

    // get v[x]
    T get_weight(int x) {
        root(x);
        return weight[x];
    }

    // get v[y] - v[x]
    T get_diff(int x, int y) { return get_weight(y) - get_weight(x); }

    // get groups
    vector<vector<int>> groups() {
        vector<vector<int>> member(par.size());
        for (int v = 0; v < (int)par.size(); ++v) {
            member[root(v)].push_back(v);
        }
        vector<vector<int>> res;
        for (int v = 0; v < (int)par.size(); ++v) {
            if (!member[v].empty()) res.push_back(member[v]);
        }
        return res;
    }
};