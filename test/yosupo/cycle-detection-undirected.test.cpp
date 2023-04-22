#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"
#include "../../graph/cycle-detection-undirected.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, M);
    // (to, eid)
    vector<pair<int, int>> edges;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        INT(a, b);
        edges.pb({a, b});
        G[a].pb({i, b});
        G[b].pb({i, a});
    }
    int L;
    vector<int> cycle_v, cycle_e;
    cycle_detection(N, M, edges, G, cycle_v, cycle_e);
    if ((int)cycle_v.size() == 0) {
        fin(-1);
    }
    print(cycle_v.size());
    print(cycle_v);
    print(cycle_e);
}