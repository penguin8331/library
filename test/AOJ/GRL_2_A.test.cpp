#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../template/template.hpp"
#include "../../graph/kruskal.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> es(E);
    for (int i = 0; i < E; i++) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
    }
    Kruskal A(es, V);
    cout << A.sum << endl;
}