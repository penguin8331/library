---
title: Lazy Segment Tree
documentation_of: //data-structure/lazy-segment-tree.hpp
---

## 概要

セグメントツリーは「作用つきモノイド」上で定義される

## 使い方

### 宣言

- FM(a, b): 2 つのモノイド間に定義される演算
- FA(a, d): モノイド元 a への作用素 d による作用
- FC(d, e): 作用素 d への作用素 e の合成
- IDENTITY_MONOID: モノイドの単位元
- IDENTITY_LAZY: 作用素の単位元

```cpp
Lazy_SegTree<int, int> seg(N, fm, fa, fc, identity_monoid, identity_lazy)
```

### ex

- starry sky tree (区間加算、区間min取得)

```cpp
auto fm = [](int a, int b) { return min(a, b); };
auto fa = [](int& a, int d) { a += d; };
auto fc = [](int& d, int e) { d += e; };
Lazy_SegTree<int, int> seg(N, fm, fa, fc, inf, 0);
```

- RMQ and RUQ (区間更新、区間min取得)

```cpp
auto fm = [](int a, int b) { return min(a, b); };
auto fa = [](int& a, int d) { a = d; };
auto fc = [](int& d, int e) { d = e; };
Lazy_SegTree<int, int> seg(N, fm, fa, fc, INT_MAX, -1);
```

- RSQ and RUQ (区間更新、区間sum取得)

```cpp
auto fm = [](pii a, pii b) {
    return pii(a.first + b.first, a.second + b.second);
};
auto fa = [](pii& a, int d) { a.first = d * a.second; };
auto fc = [](int& d, int e) { d = e; };
Lazy_SegTree<pii, int> seg(N, fm, fa, fc, {0, 1}, -inf);
seg.build();
```

- いろいろできるやつ
  - `update(i, j, {a, b})` : `[i, j)` に `ax + b` を作用
  - `update(i, j, {0, a})` : 更新
  - `update(i, j, {1, a})` : 加算
  - `update(i, j, {a, 0})` : 倍

```cpp
auto fm = [](ll a, ll b) { return max(a, b); };
auto fa = [](ll& a, pii d) { a = a * d.first + d.second; };
auto fc = [](pii& d, pii e) {
    d.first = d.first * e.first;
    d.second = d.second * e.first + e.second;
};
Lazy_SegTree<ll, pii> seg(N, fm, fa, fc, 0, {1, 0});
```

### 初期化

`init(n)` : サイズ `n` に初期化

`set(a, v)` : `a` 番目の値を `v` にセットする

`build()` : `set` した値を元にセグメントツリー全体を構築する $O(N)$

### クエリ

`update(a, b, v)` : 区間 `[a, b)` を作用素 `v` を用いて更新する $O(log N)$

`get(a, b)` : 区間 `[a, b)` についての演算結果を返す $O(log N)$
