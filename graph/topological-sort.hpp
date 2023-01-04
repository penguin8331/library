void dfs(const vector<vector<int>> &G, int v, vector<bool> &used, vector<int> &ans) {
    used[v] = true;
    for (auto e : G[v]) {
        if (!used[e]) {
            dfs(G, e, used, ans);
        }
    }
    ans.push_back(v);  // 帰りがけにpush_back
}
vector<int> topo_sort(const vector<vector<int>> &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<bool> used(n, false);
    for (int v = 0; v < n; v++) {  // 未探索の頂点ごとにDFS
        if (!used[v]) dfs(G, v, used, ans);
    }
    reverse(ans.begin(), ans.end());  // 逆向きなのでひっくり返す
    return ans;
}