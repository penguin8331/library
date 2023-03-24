#pragma once
#include "../template/template.hpp"

vector<int> BFS(const vector<vector<int>> &G, int s) {
    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int x : G[v]) {
            if (dist[x] != -1) continue;

            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}