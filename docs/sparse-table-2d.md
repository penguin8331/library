---
title: Sparse Table 2D
documentation_of: //data-structure/sparse-table-2d.hpp
---

## 使い方

### 宣言

`SparseTable(vec, F)` : 二次元配列 `vec` で構築、 `F` は二項演算

### クエリ

`query(h1, w1, h2, w2)` :  区間 $[A_{h_1,w_1}, A_{h2, w2})$ の総積を取得する。
