#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_f"
#include "../../graph/scc.hpp"
#include "../../template/template.hpp"

vector<vector<int>> G;
vector<int> dp;
bool dfs(int u) {
    if (dp[u] == 1) {
        return true;
    }
    if (dp[u] != -1) {
        return dp[u];
    }
    for (auto &i : G[u]) {
        if (dfs(i)) {
            return dp[u] = true;
        }
    }
    return dp[u] = false;
}
int main() {
    INT(N, M);
    SCC scc(N);
    for (int i = 0; i < M; i++) {
        INT(a, b);
        a--;
        b--;
        scc.addedge(a, b);
    }
    scc.solve();
    vector<vector<int>> res = scc.scc;
    dp.resize(N, -1);
    G = scc.G;
    for (auto &i : res) {
        if (i.size() >= 2) {
            for (auto &j : i) {
                dp[j] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        dfs(i);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += dp[i];
    }
    print(cnt);
}