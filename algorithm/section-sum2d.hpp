#pragma once
#include "../template/template.hpp"

template <class T>
struct SectionSum2D {
    vector<vector<T>> data;

    SectionSum2D(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}

    void update(int x, int y, const T& z) {
        x++;
        y++;
        data[x][y] = z;
    }

    void build() {
        for (int i = 1; i < data.size(); i++) {
            for (int j = 1; j < data[i].size(); j++) {
                data[i][j] +=
                    data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    T get(int lx, int ly, int rx, int ry) const {
        return (data[rx][ry] - data[lx][ry] - data[rx][ly] + data[lx][ly]);
    }
};