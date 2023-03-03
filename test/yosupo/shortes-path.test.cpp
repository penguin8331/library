#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../graph/dijkstra-route.hpp"
#include "../../template/template.hpp"

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<Edge>> G(N, vector<Edge>(0));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    vector<int> prev;
    auto res = dijkstra(G, s, prev);
    auto ans = get_path(prev, t);
    if (res[t] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << res[t] << " " << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}