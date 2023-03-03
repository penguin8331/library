#pragma once
#include "../template/template.hpp"

bool isbipartite(const vector<vector<int>>& G) {
    int N = (int)G.size();
    vector<int> color(N, -1);

    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) {
            continue;
        }
        queue<int> que;
        color[v] = 0;
        que.push(v);
        while (!que.empty()) {
            int qv = que.front();
            que.pop();
            for (auto nv : G[qv]) {
                if (color[nv] != -1) {
                    if (color[nv] == color[qv]) {
                        return false;
                    }
                    continue;
                }
                color[nv] = 1 - color[qv];
                que.push(nv);
            }
        }
    }
    return true;
}