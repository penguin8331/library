---
title: ダイクストラ法(経路復元あり)
documentation_of: //graph/dijkstra-route.hpp
---

## 使い方

- `dijkstra(G,s,dis,prev)`

    入力：グラフ `G`, 開始点 `s`, 距離を格納する `dis`, 最短経路の前の点を記録する `prev`

    計算量：$O(E log V)$

    副作用：`dis`, `prev` が書き換えられる

- `getpath(prev, t)`

    入力：`dijkstra` で得た `prev`, ゴール `t`

    出力: `s` から `t` への最短路のパス
