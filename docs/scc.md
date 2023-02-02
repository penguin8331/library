---
title: 強連結成分分解 (Strongly Connected Component)
documentation_of: //graph/scc.hpp
---

## グラフの設計

- `SCC scc(N)` : 頂点数 `N` のグラフを宣言
- `addedge(int u,int v)` : 頂点 `u` から `v` にかけて有向辺を張る

## 強連結成分分解

- `solve()` : いままで設計されたグラフを用いて強連結成分分解する  
結果は以下の要素に格納される
  - `scc[i]` : トポロジカルソートして `i` 個目となる連結成分となる頂点
  - `cmp[i]` : 頂点 `i` が `scc` の何個目の連結成分に属するか
