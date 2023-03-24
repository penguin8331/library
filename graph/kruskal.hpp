#pragma once
#include "../template/template.hpp"
#include "../data-structure/union-find.hpp"

struct Edge {
    long long from;
    long long to;
    long long cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }
struct Kruskal {
    UnionFind uft;
    long long sum;
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
    void init() {
        sort(edges.begin(), edges.end(), comp_e);
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges) {
            if (!uft.issame(e.from, e.to)) {
                uft.unite(e.from, e.to);
                sum += e.cost;
            }
        }
    }
};