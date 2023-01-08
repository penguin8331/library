---
title: 巡回セールスマン問題(bitDP)
documentation_of: //dynamic-programming/traveling-salesman-problem.hpp
---

## 使い方

`dp[S][i]` = `S` を周って `i` に着くような経路の最短の長さ

`G` -> パスがあればその距離、なければ `INF` をいれる (オーバーフローしないように注意)
