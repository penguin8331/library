#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"
#include "../../graph/tree/euler-tour-on-nodes.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, Q);
    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        INT(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    EulerTour et(G);
    for (int i = 0; i < Q; i++) {
        INT(t);
        if (t == 0) {
            INT(u, v);
            print(et.get(u, v));
        } else {
            INT(u, x);
            et.update(u, x);
        }
    }
}