---
title: Bellman–Ford
documentation_of: //graph/bellman-ford.hpp
---

## 使い方

`bellman_ford(vector<Edge> Es,int V,int s,vector<long long> dis)`

入力: 全ての辺 `Es`, 頂点数 `V`, 開始点 `s`, 最短経路を記録する `dis`

出力: 負の閉路が存在するなら `true`

計算量: $O(VE)$

副作用: `dis` が書き換えられる
