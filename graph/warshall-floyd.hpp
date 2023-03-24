#pragma once
#include "../template/template.hpp"

void warshallfloyd(vector<vector<long long>> &dp, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}
bool isnegative(vector<vector<long long>> dp, int V) {
    bool isnegative = false;
    for (int v = 0; v < V; ++v) {
        if (dp[v][v] < 0) isnegative = true;
    }
    return isnegative;
}