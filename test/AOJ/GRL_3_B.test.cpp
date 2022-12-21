#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include "template/template.hpp"
#include "graph/low-link.hpp"

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
    auto ans = A.brs;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].first > ans[i].second) {
            swap(ans[i].first, ans[i].second);
        }
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
