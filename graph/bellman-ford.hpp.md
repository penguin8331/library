---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman-ford.hpp\"\nstruct Edge {\n    long long from;\n\
    \    long long to;\n    long long cost;\n};\nconst long long INF = 1LL << 60;\n\
    bool bellman_ford(const vector<Edge> &Es, int V, int s, vector<long long> &dis)\
    \ {\n    dis.resize(V, INF);\n    dis[s] = 0;\n    int cnt = 0;\n    while (cnt\
    \ < V) {\n        bool end = true;\n        for (auto e : Es) {\n            if\
    \ (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {\n               \
    \ dis[e.to] = dis[e.from] + e.cost;\n                end = false;\n          \
    \  }\n        }\n        if (end) break;\n        cnt++;\n    }\n    return (cnt\
    \ == V);\n}\n"
  code: "struct Edge {\n    long long from;\n    long long to;\n    long long cost;\n\
    };\nconst long long INF = 1LL << 60;\nbool bellman_ford(const vector<Edge> &Es,\
    \ int V, int s, vector<long long> &dis) {\n    dis.resize(V, INF);\n    dis[s]\
    \ = 0;\n    int cnt = 0;\n    while (cnt < V) {\n        bool end = true;\n  \
    \      for (auto e : Es) {\n            if (dis[e.from] != INF && dis[e.from]\
    \ + e.cost < dis[e.to]) {\n                dis[e.to] = dis[e.from] + e.cost;\n\
    \                end = false;\n            }\n        }\n        if (end) break;\n\
    \        cnt++;\n    }\n    return (cnt == V);\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman-ford.hpp
layout: document
title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
---

##　概要

$bellmanford(Es,s,t,dis)$<br>
入力: 全ての辺$Es$, 頂点数$V$, 開始点 $s$, 最短経路を記録する$dis$<br>
出力: 負の閉路が存在するなら $true$<br>
計算量：$O(|E||V|)$<br>
副作用：$dis$ が書き換えられる<br>