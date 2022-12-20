vector<int> BFS(const vector<vector<int>> &G, int s) {
    int N = (int)G.size();    // 頂点数
    vector<int> dist(N, -1);  // すべての頂点を未訪問に初期化
    queue<int> que;

    // 初期条件 (頂点sを初期頂点とする)
    dist[s] = 0;
    que.push(s);  // sを探索済み頂点に

    // BFS開始
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        // 頂点vからたどれる頂点を全て調べる
        for (int x : G[v]) {
            // すでに発見済みの頂点は探索しない
            if (dist[x] != -1) continue;

            // 新たな未探索頂点xについて距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}