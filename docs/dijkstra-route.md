---
title: ダイクストラ法(経路復元あり)
documentation_of: //graph/dijkstra-route.hpp
---

## 概要

$dijkstra(G,s,dis,prev)$<br>
入力：グラフ $G$, 開始点 $s$, 距離を格納する $dis$, 最短経路の前の点を記録する $prev$<br>
計算量：$O(|E|log|V|)$<br>
副作用：$dis$, $prev$が書き換えられる

$getpath(prev, t)$<br>
入力：$dijkstra$ で得た $prev$, ゴール $t$<br>
出力： $s$から$t$への最短路のパス
