#pragma once
#include "../template/template.hpp"

int LCS(const string& a, const string& b) {
    const int n = a.size(), m = b.size();
    vector<vector<int> > X(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                X[i + 1][j + 1] = X[i][j] + 1;
            } else if (X[i + 1][j] < X[i][j + 1]) {
                X[i + 1][j + 1] = X[i][j + 1];
            } else {
                X[i + 1][j + 1] = X[i + 1][j];
            }
        }
    }
    return X[n][m];
}