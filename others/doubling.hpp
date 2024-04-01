#pragma once
#include "../template/template.hpp"

struct Doubling {
    vector<vector<int>> table;
    const vector<int> data;
    int sz;
    int LOG;
    unsigned long long MAX;

    Doubling(const vector<int> &data, const unsigned long long &MAX)
        : data(data), MAX(MAX), LOG(64 - __builtin_clzll(MAX)) {
        sz = data.size();
        table.assign(LOG, vector<int>(sz));
        table[0] = data;
        for (int k = 0; k < LOG - 1; k++) {
            for (int i = 0; i < sz; i++) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int get(int v, unsigned long long k) {
        assert(k <= MAX);
        int now = v;
        for (int i = 0; i < LOG; i++) {
            if (k & 1) now = table[i][now];
            k = k >> 1;
        }
        return now;
    }
};