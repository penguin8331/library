---
title: ベルマンフォード法
documentation_of: //graph/bellman-ford.hpp
---

##　概要

$bellmanford(Es,s,t,dis)$<br>
入力: 全ての辺$Es$, 頂点数$V$, 開始点 $s$, 最短経路を記録する$dis$<br>
出力: 負の閉路が存在するなら $true$<br>
計算量：$O(|E||V|)$<br>
副作用：$dis$ が書き換えられる<br>