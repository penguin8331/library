---
title: セグメント木
documentation_of: //data-structure/segment-tree.hpp
---

## 概要


セグメントツリーは二項演算の定義されたモノイド上で定義される<br>
二項演算関数 f(x, y) を構造体に渡す<br>

### 宣言

SegTree(n, f, unity): サイズ n に初期化、f は二項演算、unity は単位元 (min なら INF, + なら 0)<br>

### ex
- 区間和: SegTree<int> seg(n, [](int a, int b){ return a + b; }, 0);
- 区間min: SegTree<int> seg(n, [](int a, int b}{ return min(a, b); }, INF);


### 初期化

init(n): サイズ n に初期化<br>
set(a, v): a 番目の値を v にセットする<br>
build(): set した値を元にセグメントツリー全体を構築する、O(n)<br>

### クエリ

update(a, v): a 番目の値を v に更新する, O(log n)<br>
get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)<br>
