#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include "template/template.hpp"
#include "graph/scc.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    SCC scc(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        scc.addedge(a, b);
    }
    scc.solve();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (scc.cmp[u] == scc.cmp[v] ? 1 : 0) << endl;
    }
}