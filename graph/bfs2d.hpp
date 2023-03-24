#pragma once
#include "../template/template.hpp"

vector<vector<int>> BFS(int H, int W, const vector<string> &G, pair<int, int> s) {
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;

    dist[s.first][s.second] = 0;
    que.push(s);

    while (!que.empty()) {
        pair<int, int> v = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int X = dx[i] + v.first;
            int Y = dy[i] + v.second;
            if (X < 0 || X >= H || Y < 0 || Y >= W) continue;
            if (dist[X][Y] != -1 || G[X][Y] == '#') continue;

            dist[X][Y] = dist[v.first][v.second] + 1;
            que.push(make_pair(X, Y));
        }
    }
    return dist;
}