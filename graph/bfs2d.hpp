#pragma once
#include "../template/template.hpp"

vector<vector<int>> BFS(int H, int W, const vector<string> &G, pair<int, int> s) {
    vector<vector<int>> dist(H, vector<int>(W, -1));  //すべての頂点を未訪問に初期化
    queue<pair<int, int>> que;

    //初期条件 (頂点sを初期頂点とする)
    dist[s.first][s.second] = 0;
    que.push(s);  // sを探索済み頂点に

    // BFS開始
    while (!que.empty()) {
        pair<int, int> v = que.front();
        que.pop();

        //頂点vからたどれる頂点を全て調べる
        for (int i = 0; i < 4; i++) {
            int X = dx[i] + v.first;
            int Y = dy[i] + v.second;
            if (X < 0 || X >= H || Y < 0 || Y >= W) continue;
            //すでに発見済みの頂点は探索しない
            if (dist[X][Y] != -1 || G[X][Y] == '#') continue;

            //新たな未探索点xについて距離情報を更新してキューに挿入
            dist[X][Y] = dist[v.first][v.second] + 1;
            que.push(make_pair(X, Y));
        }
    }
    return dist;
}