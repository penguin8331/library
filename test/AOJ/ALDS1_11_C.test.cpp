#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include "../../graph/bfs.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    auto res = BFS(G, 0);
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " " << res[i] << endl;
    }
}