#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "../../graph/bellman-ford.hpp"
#include "../../template/template.hpp"

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<Edge> es(E);
    for (int i = 0; i < E; i++) {
        Edge a;
        cin >> a.from >> a.to >> a.cost;
        es[i] = a;
    }
    vector<ll> dis(V);
    if (bellman_ford(es, V, r, dis)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; i++) {
            if (dis[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << dis[i] << endl;
            }
        }
    }
}