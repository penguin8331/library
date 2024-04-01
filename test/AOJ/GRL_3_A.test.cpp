#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include "../../graph/low-link.hpp"
#include "../../template/template.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V, vector<int>(0));
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    LowLink A;
    A.solve(G);
    auto ans = A.aps;
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}