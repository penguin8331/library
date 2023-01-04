#include#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "template/template.hpp"
#include "graph/topological-sort.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V, vector<int>(0));
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    auto ans = topo_sort(G);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}