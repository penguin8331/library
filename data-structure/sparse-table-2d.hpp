#pragma once
#include "../template/template.hpp"

template <class T>
struct SparseTable2D {
    vector<vector<vector<vector<T>>>> dat;
    vector<int> height;
    using Func = function<T(T, T)>;
    Func F;

    SparseTable2D() {}
    explicit SparseTable2D(
        const vector<vector<T>> &vec,
        const Func f = [](T a, T b) { return min(a, b); }) {
        init(vec, f);
    }
    void init(
        const vector<vector<T>> &vec,
        const Func f = [](T a, T b) { return min(a, b); }) {
        F = f;
        int n = (int)vec.size(), m = (int)vec[0].size();
        height.assign(max(n, m) + 1, 0);
        for (int i = 2; i <= max(n, m); i++) {
            height[i] = height[i >> 1] + 1;
        }
        dat.assign(height[n] + 1,
                   vector<vector<vector<T>>>(
                       height[m] + 1, vector<vector<T>>(n, vector<T>(m))));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dat[0][0][i][j] = vec[i][j];
            }
        }
        for (int k = 1; (1 << k) <= n; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                for (int j = 0; j < m; ++j) {
                    dat[k][0][i][j] = F(dat[k - 1][0][i][j],
                                        dat[k - 1][0][i + (1 << (k - 1))][j]);
                }
            }
        }
        for (int k = 0; (1 << k) <= n; ++k) {
            for (int l = 1; (1 << l) <= m; ++l) {
                for (int i = 0; i + (1 << k) <= n; ++i) {
                    for (int j = 0; j + (1 << l) <= m; ++j) {
                        dat[k][l][i][j] =
                            F(dat[k][l - 1][i][j],
                              dat[k][l - 1][i][j + (1 << (l - 1))]);
                    }
                }
            }
        }
    }
    T query(int h1, int w1, int h2, int w2) {
        int h = height[h2 - h1], w = height[w2 - w1];
        return F(dat[h][w][h1][w1],
                 F(dat[h][w][h2 - (1 << h)][w1],
                   F(dat[h][w][h1][w2 - (1 << w)],
                     dat[h][w][h2 - (1 << h)][w2 - (1 << w)])));
    }
};
