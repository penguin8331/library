#pragma once
#include "../template/template.hpp"

struct traveling_salesman {
    int V;
    vector<vector<ll>> dp;
    vector<vector<ll>> G;
    ll ans;
    traveling_salesman(vector<vector<ll>> G) : G(G) {
        V = G.size();
        dp.assign(1 << V, vector<ll>(V, 0));
        ans = solve((1 << V) - 1, 0);
    }
    ll solve(int S, int v) {
        if (S == 0) {
            if (v == 0) {
                return 0;
            } else {
                return inf;
            }
        }
        if ((S & (1 << v)) == 0) {
            return inf;
        }
        ll& ret = dp[S][v];
        if (ret != 0) return ret;
        ret = inf;
        for (int u = 0; u < V; u++) {
            chmin(ret, solve(S ^ (1 << v), u) + G[u][v]);
        }
        return ret;
    }
};