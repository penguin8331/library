---
title: PairQuery
documentation_of: //data-structure/pair-query-by-implicit-treap.hpp
---

## 宣言

```cpp
PairQuery<T0, T1, bool ascending = true> hoge;
```

`pair<T0,T1>` 集合が要素の型となる、 `accending` は要素を昇順にするかどうか

## クエリ

`void add(pair<T0, T1> &a)` : 集合に `a` を追加 $O(log n)$

`void erase_at(int k)` : 位置を指定して要素を削除。先頭の削除なら `k = 0` を指定。 $O(log n)$

`void erase_value(T a)` : 要素を指定して削除。 `a` がすでに `add` されていることが仮定されている。 $O(logn)$

`int size()` : 現時点でのサイズを返す $O(1)$

`T sum(int k)` : 先頭 `k` 要素の総和を返す。 $O(log n)$

`T0 operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。
