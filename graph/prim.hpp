#pragma once
#include "../template/template.hpp"

struct Edge {
    int to;
    long long cost;
};
struct Prim {
    vector<vector<Edge>> G;
    int V;
    long long sum;
    Prim(vector<vector<Edge>> &G_, int V_) : G(G_), V(V_) {
        sum = 0;
        vector<bool> seen(V, false);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push(mp(0, 0));
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (seen[p.second]) continue;
            seen[p.second] = true;
            sum += p.first;
            for (const auto &i : G[p.second]) {
                pq.push(mp(i.cost, i.to));
            }
        }
    }
};