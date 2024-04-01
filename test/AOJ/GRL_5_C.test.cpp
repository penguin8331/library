#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include "../../graph/lca.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            G[i].push_back(a);
        }
    }
    LCA lca(G, 0);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.get(u, v) << endl;
    }
}