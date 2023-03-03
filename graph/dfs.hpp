#pragma once
#include "template/template.hpp"

vector<bool> seen;
void dfs(const vector<vector<int>>& G, int v) {
    seen[v] = true;

    // vから行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;  //探索済みなら捜索しない
        dfs(G, next_v);
    }
}