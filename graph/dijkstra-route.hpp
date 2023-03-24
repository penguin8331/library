#pragma once
#include "../template/template.hpp"

struct Edge {
    long long to;
    long long cost;
};
vector<long long> dijkstra(const vector<vector<Edge>> &G, int s, vector<int> &prev) {
    int N = G.size();
    vector<long long> dis(N, INF);
    prev.assign(N, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        pair<long long, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
    return dis;
}
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}