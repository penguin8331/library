---
title: 遅延評価付きセグメント木
documentation_of: //data-structure/lazy-segment-tree.hpp
---

## 概要

セグメントツリーは「作用つきモノイド」上で定義される
- FM(a, b): 2 つのモノイド間に定義される演算
- FA(a, d): モノイド元 a への作用素 d による作用
- FC(d, e): 作用素 d への作用素 e の合成
- IDENTITY_MONOID: モノイドの単位元
- IDENTITY_LAZY: 作用素の単位元

### 宣言

Lazy_SegTree<int, int> seg(N, fm, fa, fc, identity_monoid, identity_lazy)

### ex

- starry sky tree (区間加算、区間min取得)
  - auto fm = [](int a, int b) { return min(a, b); };
  - auto fa = [](int& a, int d) { a += d; };
  - auto fc = [](int& d, int e) { d += e; };
  - Lazy_SegTree<int, int> seg(N, fm, fa, fc, (1LL << 60), 0);

### 初期化

init(n): サイズ n に初期化<br>
set(a, v): a 番目の値を v にセットする<br>
build(): set した値を元にセグメントツリー全体を構築する、O(n)

### クエリ

update(a, b, v): 区間 [a, b) を作用素 v を用いて更新する, O(log n)<br>
get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)<br>
