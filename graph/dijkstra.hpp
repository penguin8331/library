struct Edge {
    long long to;
    long long cost;
};
Edge make_edge(int to, int cost) {
    Edge a;
    a.to = to;
    a.cost = cost;
    return a;
}
vector<long long> dijkstra(const vector<vector<Edge>> &G, int s) {
    int N = G.size();
    vector<long long> dis(N, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        pair<long long, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
    return dis;
}
