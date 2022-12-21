---
title: 巡回セールスマン問題(bitDP)
documentation_of: //dynamic-programming/traveling-salesman-problem.hpp
---

## 概要

$dp[S][i]$ = $S$を周って$i$に着くような経路の最短の長さ<br>
$G$->パスがあればその距離,なければINFをいれる(オーバーフローしないように注意)
