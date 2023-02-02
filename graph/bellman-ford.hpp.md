---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman-ford.hpp\"\nstruct Edge {\n    long long from;\n\
    \    long long to;\n    long long cost;\n};\nbool bellman_ford(const vector<Edge>\
    \ &Es, int V, int s, vector<long long> &dis) {\n    dis.assign(V, INF);\n    dis[s]\
    \ = 0;\n    int cnt = 0;\n    while (cnt < V) {\n        bool end = true;\n  \
    \      for (auto e : Es) {\n            if (dis[e.from] != INF && dis[e.from]\
    \ + e.cost < dis[e.to]) {\n                dis[e.to] = dis[e.from] + e.cost;\n\
    \                end = false;\n            }\n        }\n        if (end) break;\n\
    \        cnt++;\n    }\n    return (cnt == V);\n}\n"
  code: "struct Edge {\n    long long from;\n    long long to;\n    long long cost;\n\
    };\nbool bellman_ford(const vector<Edge> &Es, int V, int s, vector<long long>\
    \ &dis) {\n    dis.assign(V, INF);\n    dis[s] = 0;\n    int cnt = 0;\n    while\
    \ (cnt < V) {\n        bool end = true;\n        for (auto e : Es) {\n       \
    \     if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {\n        \
    \        dis[e.to] = dis[e.from] + e.cost;\n                end = false;\n   \
    \         }\n        }\n        if (end) break;\n        cnt++;\n    }\n    return\
    \ (cnt == V);\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2022-12-21 22:31:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_B.test.cpp
documentation_of: graph/bellman-ford.hpp
layout: document
title: "Bellman\u2013Ford"
---

## 使い方

`bellman_ford(vector<Edge> Es,int V,int s,vector<long long> dis)`

入力: 全ての辺 `Es`, 頂点数 `V`, 開始点 `s`, 最短経路を記録する `dis`

出力: 負の閉路が存在するなら `true`

計算量: $O(VE)$

副作用: `dis` が書き換えられる
