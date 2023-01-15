---
title: ImplicitTreap
documentation_of: //data-structure/implicit-treap.hpp
---

## 宣言

```cpp
MinUpdateQuery<T0, T1> hoge;
```

`T0` はもとの配列の型、 `T1` は作用素の型

型は以下の通り

```cpp
MinUpdateQuery
SumAddQuery
MinAddQuery
SumUpdateQuery
SumAffineQuery
MinmaxAffineQuery
```

## クエリ

`int size()` : 現時点でのサイズを返す $O(1)$

`void insert(int pos, T0 x)` : 先頭から `pos` の位置に `x` を挿入します $O(log n)$

`void update(int l, int r, T1 x)` : `[l,r)` の半開区間に `x` を作用させる

`T0 query(int l, int r)` : `[l,r)` の半開区間について累積を求める $O(log n)$

`int binary_search(int l, int r, T0 x, bool left = true)` : 累積用の演算が `min` の場合、 `[l, r)` の範囲にある `x` 未満の最左/最右の要素の位置を返す

`void erase(int pos)` : 位置 `pos` の要素を削除します $O(log n)$

`void reverse(int l, int r)` : 区間 `[l, r)` を反転します $O(logn)$

`void rotate(int l, int m, int r)` : 区間の `[l, r)` の先頭が `m` になるようにシフトさせます。 `std::rotate` と同じ仕様です。 $O(logn)$

`T0 operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。

### [記事](https://xuzijian629.hatenablog.com/entry/2019/10/25/234938)
