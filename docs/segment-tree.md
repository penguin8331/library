---
title: Segment Tree
documentation_of: //data-structure/segment-tree.hpp
---

## 概要

セグメントツリーは二項演算の定義されたモノイド上で定義される

## 使い方

### 宣言

`SegTree(n, f, unity)` : サイズ `n` に初期化、 `f` は二項演算、 `unity` は単位元 ( `min` なら `INF`, `+` なら `0`)

### ex

- 区間和:

```cpp
SegTree<int> seg(n, [](int a, int b){ return a + b; }, 0);
```

- 区間min:

```cpp
SegTree<int> seg(n, [](int a, int b){ return min(a, b); }, INF);
```

### 初期化

`init(n)` : サイズ `n` に初期化

`set(a, v)` : `a` 番目の値を `v` にセットする

`build()` : `set` した値を元にセグメントツリー全体を構築する $O(n)$

### クエリ

`update(a, v)` : `a` 番目の値を `v` に更新する $O(log N)$

`get(a, b)`: 区間 `[a, b)` についての演算結果を返す $O(log n)$
