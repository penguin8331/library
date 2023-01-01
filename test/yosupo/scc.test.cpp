#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "template/template.hpp"
#include "graph/scc.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    SCC scc(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        scc.addedge(a, b);
    }
    scc.solve();
    auto ans = scc.scc;
    cout << ans.size() << endl;
    for (const auto& i : ans) {
        cout << i.size();
        for (const auto& j : i) {
            cout << " " << j;
        }
        cout << endl;
    }
}