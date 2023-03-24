#pragma once
#include "../template/template.hpp"

vector<vector<long long>> dijkstra(int H, int W, vector<string> G, pair<int, int> s) {
    vector<vector<long long>> dis(H, vector<long long>(W, INF));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    dis[s.first][s.second] = 0;
    pq.emplace(dis[s.first][s.second], s);
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        auto v = p.second;
        if (dis[v.first][v.second] < p.first) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int X = v.first + dx[i];
            int Y = v.second + dy[i];
            if (X < 0 || X >= H || Y < 0 || Y >= W) continue;
            int cost = dis[v.first][v.second] + (G[X][Y] == '#' ? 1 : 0);
            if (dis[X][Y] > cost) {
                dis[X][Y] = cost;
                pq.emplace(dis[X][Y], pair<int, int>(X, Y));
            }
        }
    }
    return dis;
}