#pragma once
#include "../template/template.hpp"

template <class T>
struct SparseTable {
    vector<vector<T>> dat;
    vector<int> height;
    using Func = function<T(T, T)>;
    Func F;

    SparseTable() {}
    SparseTable(
        const vector<T> &vec, const Func f = [](T a, T b) { return min(a, b); }) : F(f) {
        init(vec);
    }
    void init(const vector<T> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1 << h) < n) ++h;
        dat.assign(h, vector<T>(1 << h));
        height.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = F(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);
    }

    T get(int a, int b) {
        return F(dat[height[b - a]][a], dat[height[b - a]][b - (1 << height[b - a])]);
    }
};