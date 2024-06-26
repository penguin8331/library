#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../graph/dijkstra.hpp"
#include "../../template/template.hpp"

int main() {
    int N, E, r;
    cin >> N >> E >> r;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }
    auto res = dijkstra(G, r);
    for (int i = 0; i < N; i++) {
        if (res[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << res[i] << endl;
        }
    }
}
