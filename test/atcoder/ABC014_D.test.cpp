#define PROBLEM "https://atcoder.jp/contests/abc014/tasks/abc014_4"
#include "../../graph/lca.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N);
    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        INT(u, v);
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LCA lca(G);
    INT(Q);
    for (int i = 0; i < Q; i++) {
        INT(a, b);
        a--;
        b--;
        print(lca.dist(a, b) + 1);
    }
}