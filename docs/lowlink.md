---
title: Low-Link(橋,関節点列挙)
documentation_of: //graph/low-link.hpp
---

## 概要

アイディア: DFS をしたとき、DFS 後退辺は橋とはなりえない<br>

* $ord[v]$ := 頂点を訪れた順番<br>
* $low[v]$ := $v$から「DFS 木の根から葉へ進む」or「後退辺を葉から根へ進む」ことによって辿り着ける頂点の$ord$の最小値

DFS で $u$ -> ... -> $v$ と来て、$v$ から $u$ への後退辺があると、このサイクルの $low$ がすべて $ord[u]$ (以下) になる感じ

このことから、DFS-search で、辺 $v$ - $ch$ を $v$ -> $ch$ の順に探索したときに、
辺 $v$-$to$ が橋　⇔　$ord[v]$ < $low[ch]$

DFS-search で
頂点 $v$ が関節点　⇔
* $v$ が根のとき、$deg[v]$ > 1<br>
* それ以外のとき、$u$ のある子供 $ch$ が存在して、$ord[v]$ <= $low[ch]$