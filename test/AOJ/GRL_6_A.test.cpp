#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../../graph/flow/ford-fullkerson.hpp"
#include "../../template/template.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    Graph<int> G(V);
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        G.addedge(u, v, c);
    }
    FordFulkerson<int> ff;
    int s = 0, t = V - 1;
    cout << ff.solve(G, s, t) << endl;
}