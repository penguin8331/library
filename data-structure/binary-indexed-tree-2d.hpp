#pragma once
#include "../template/template.hpp"

template <class Abel>
struct BIT2D {
    const Abel UNITY_SUM = 0;
    vector<vector<Abel>> dat;

    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),
                                          dat(n, vector<Abel>(m, UNITY_SUM)) {}
    void init(int n, int m) {
        dat.assign(n, vector<Abel>(m, UNITY_SUM));
    }

    inline void add(int a, int b, Abel x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            for (int j = b; j < (int)dat[0].size(); j |= j + 1)
                dat[i][j] = dat[i][j] + x;
    }

    inline Abel sum(int p, int q) {
        Abel res = UNITY_SUM;
        for (int i = p - 1; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = q - 1; j >= 0; j = (j & (j + 1)) - 1)
                res = res + dat[i][j];
        return res;
    }

    inline Abel sum(int x1, int x2, int y1, int y2) {
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }

    friend ostream& operator<<(ostream& os, BIT2D bit) {
        for (int i = 0; i < (int)bit.dat.size(); i++) {
            os << "[ ";
            for (int j = 0; j < (int)bit.dat[0].size(); j++) {
                os << bit.sum(i, i + 1, j, j + 1) << " ";
            }
            os << ']';
        }
        return os;
    }
};