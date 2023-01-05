---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_C.test.cpp
    title: test/AOJ/GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.hpp\"\nstruct LCA {\n    vector<vector<int>> parent;\
    \  // parent[d][v] := 2^d-th parent of v\n    vector<int> depth;\n    LCA() {}\n\
    \    LCA(const vector<vector<int>> &G, int r = 0) { init(G, r); }\n    void init(const\
    \ vector<vector<int>> &G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V,\
    \ -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for\
    \ (int i = 0; i + 1 < (int)parent.size(); ++i)\n            for (int v = 0; v\
    \ < V; ++v)\n                if (parent[i][v] != -1)\n                    parent[i\
    \ + 1][v] = parent[i][parent[i][v]];\n    }\n    void dfs(const vector<vector<int>>\
    \ &G, int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n\
    \        for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n \
    \   }\n    int get(int u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n\
    \        for (int i = 0; i < (int)parent.size(); ++i)\n            if ((depth[v]\
    \ - depth[u]) & (1 << i))\n                v = parent[i][v];\n        if (u ==\
    \ v) return u;\n        for (int i = (int)parent.size() - 1; i >= 0; --i) {\n\
    \            if (parent[i][u] != parent[i][v]) {\n                u = parent[i][u];\n\
    \                v = parent[i][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n};\n"
  code: "struct LCA {\n    vector<vector<int>> parent;  // parent[d][v] := 2^d-th\
    \ parent of v\n    vector<int> depth;\n    LCA() {}\n    LCA(const vector<vector<int>>\
    \ &G, int r = 0) { init(G, r); }\n    void init(const vector<vector<int>> &G,\
    \ int r = 0) {\n        int V = (int)G.size();\n        int h = 1;\n        while\
    \ ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V, -1));\n       \
    \ depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for (int i = 0; i +\
    \ 1 < (int)parent.size(); ++i)\n            for (int v = 0; v < V; ++v)\n    \
    \            if (parent[i][v] != -1)\n                    parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \    }\n    void dfs(const vector<vector<int>> &G, int v, int p, int d) {\n  \
    \      parent[0][v] = p;\n        depth[v] = d;\n        for (auto e : G[v])\n\
    \            if (e != p) dfs(G, e, v, d + 1);\n    }\n    int get(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) swap(u, v);\n        for (int i = 0; i <\
    \ (int)parent.size(); ++i)\n            if ((depth[v] - depth[u]) & (1 << i))\n\
    \                v = parent[i][v];\n        if (u == v) return u;\n        for\
    \ (int i = (int)parent.size() - 1; i >= 0; --i) {\n            if (parent[i][u]\
    \ != parent[i][v]) {\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2023-01-05 11:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_C.test.cpp
documentation_of: graph/lca.hpp
layout: document
title: "\u6700\u8FD1\u5171\u901A\u7956\u5148(LCA)"
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
