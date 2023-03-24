#pragma once
#include "../template/template.hpp"

void dfs(const vector<vector<int>> &G, int v, vector<bool> &used, vector<int> &ans) {
    used[v] = true;
    for (auto e : G[v]) {
        if (!used[e]) {
            dfs(G, e, used, ans);
        }
    }
    ans.push_back(v);
}
vector<int> topo_sort(const vector<vector<int>> &G) {
    vector<int> ans;
    int n = (int)G.size();
    vector<bool> used(n, false);
    for (int v = 0; v < n; v++) {
        if (!used[v]) dfs(G, v, used, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}