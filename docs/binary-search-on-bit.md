---
title: BIT 上の二分探索 (k番目の要素を求める)
documentation_of: //data-structure/binary-search-on-bit.hpp
---

## 概要

BIT上二分探索 (以下のクエリに答えられる、ただし `v` <= `N` として$O(N)$のメモリが必要、時間計算量は $O(log N)$)

## 使い方

- `add(v,1)`  集合 `S` に要素 `v` を追加する
- `add(v,-1)` 集合 `S` から要素 `v` を除く
- `get(k)`    集合 `S` の `k` 番目に大きい要素を答える
