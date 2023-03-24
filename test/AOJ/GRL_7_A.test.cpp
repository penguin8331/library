#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"
#include "template/template.hpp"
#include "graph/flow/ford-fullkerson.hpp"

int main() {
    INT(X, Y, E);
    Graph<int> G(X + Y + 2);
    for (int i = 0; i < X; i++) {
        G.addedge(0, i + 1, 1);
    }
    for (int i = 0; i < E; i++) {
        INT(x, y);
        x++;
        y += X + 1;
        G.addedge(x, y, 1);
    }
    for (int i = 0; i < Y; i++) {
        G.add_undirected_edge(i + X + 1, X + Y + 1, 1);
    }
    FordFulkerson<int> ff;
    cout << ff.solve(G, 0, X + Y + 1) << endl;
}