---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_2_A.test.cpp
    title: test/AOJ/DPL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dynamic-programming/traveling-salesman-problem.hpp\"\nint\
    \ V, E;\nint G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\n// \u30E1\u30E2\
    \u5316\u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n        if (v\
    \ == 0) {\n            return 0;\n        } else {\n            return inf / 3;\n\
    \        }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\u542B\u307E\
    \u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n    int &ret =\
    \ dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n    for (int u\
    \ = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);\n  \
    \  }\n    return ret;\n}\n"
  code: "int V, E;\nint G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\n//\
    \ \u30E1\u30E2\u5316\u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n\
    \        if (v == 0) {\n            return 0;\n        } else {\n            return\
    \ inf / 3;\n        }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\
    \u542B\u307E\u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n \
    \   int &ret = dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n\
    \    for (int u = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) +\
    \ G[u][v]);\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/traveling-salesman-problem.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_2_A.test.cpp
documentation_of: dynamic-programming/traveling-salesman-problem.hpp
layout: document
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C(bitDP)"
---

## 使い方

`dp[S][i]` = `S` を周って `i` に着くような経路の最短の長さ

`G` -> パスがあればその距離、なければ `INF` をいれる (オーバーフローしないように注意)
