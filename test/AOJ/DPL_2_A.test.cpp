#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"
#include "../../dynamic-programming/traveling-salesman-problem.hpp"
#include "../../template/template.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<ll>> G(V, vector<ll>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G[i][j] = inf;
        }
    }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    traveling_salesman tsp(G);
    ll ans = tsp.ans;
    cout << (ans == inf ? -1 : ans) << endl;
}