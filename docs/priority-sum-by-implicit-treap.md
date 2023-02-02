---
title: PrioritySum (by Implicit Treap)
documentation_of: //data-structure/priority-sum-by-implicit-treap.hpp
---

## 概要

集合を sort したときの上位 k 個の累積が求められる

## 宣言

```cpp
PrioritySum<T, bool ascending = true> hoge;
```

`T` 集合の要素の型、 `accending` は要素を昇順にするかどうか

## クエリ

`void add(T a)` : 集合に `a` を追加 $O(log n)$

`void erase_at(int k)` : 位置を指定して要素を削除。先頭の削除なら `k = 0` を指定。 $O(log n)$

`void erase_value(T a)` : 要素を指定して削除。 `a` がすでに `add` されていることが仮定されている。 $O(log n)$

`int size()` : 現時点でのサイズを返す $O(1)$

`T query(int k)` : 上位 k 個の累積

`T operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。
