#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_f"
#include "../../graph/tree/euler-tour-on-edges.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N);
    if (N == 1) {
        INT(Q);
        for (int i = 0; i < Q; i++) {
            INT(a, b, c);
            if (a == 2) {
                print(0);
            }
        }
        return 0;
    }
    vector<vector<Edge>> G(N);
    for (int i = 0; i < N - 1; i++) {
        INT(u, v, w);
        u--;
        v--;
        G[u].push_back({v, w, i});
        G[v].push_back({u, w, i});
    }
    EulerTour et(G);
    INT(Q);
    for (int i = 0; i < Q; i++) {
        INT(t, a, b);
        if (t == 1) {
            a--;
            et.update(a, b);
        } else {
            a--;
            b--;
            print(et.get(a, b));
        }
    }
}