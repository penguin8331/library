---
title: Dijkstra (経路復元あり)
documentation_of: //graph/dijkstra-route.hpp
---

## 使い方

- `dijkstra(vector<vector<Edge>> G,int s,vector<int> prev)`

    入力：グラフ `G`, 開始点 `s`, 最短経路の前の点を記録する `prev`

    出力: 開始点 `s` から各頂点への最短距離

    計算量：$O(E log V)$

    副作用：`prev` が書き換えられる

- `getpath(prev, t)`

    入力：`dijkstra` で得た `prev`, ゴール `t`

    出力: `s` から `t` への最短路のパス
