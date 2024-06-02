---
title: ext/pb_ds
documentation_of: //data-structure/ext-pb_ds.hpp
---

## 概要

- `ordered_set<Key, Comp_Fn=less<Key>>`  
  `std::set` の上位互換
  - `find_by_order(k)` : `k` 番目の要素のイテレータ
  - `order_of_key(k)` : `k` 未満の数が何個か
- `gp_hash_map<T, U>`  
  `std::map`の上位互換

## 参考

[Policy Based Data Structures - Joeの精進記録](https://xuzijian629.hatenablog.com/entry/2018/12/01/000010)
