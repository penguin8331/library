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
  bundledCode: "#line 1 \"dynamic-programming/traveling-salesman-problem.hpp\"\n/*\n\
    \    0->1->2->3->0\u304C\u6700\u77ED\u3060\u3068\u3059\u308B\n    dp[{0,1,2,3}][0]->dp[{1,2,3}][3]\n\
    \    ->dp[{1,2}][2]->dp[{1}][1]->dp[{}][0]\n    inf\u306E\u5024\u3092\u8ABF\u6574\
    \u3057\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\
    \u306B\u3059\u308B\n    G->\u30D1\u30B9\u304C\u3042\u308C\u3070\u305D\u306E\u8DDD\
    \u96E2,\u306A\u3051\u308C\u3070INF\u3092\u3044\u308C\u308B\n*/\nint V, E;\nint\
    \ G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\n// \u30E1\u30E2\u5316\
    \u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n        if (v == 0)\
    \ {\n            return 0;\n        } else {\n            return inf / 3;\n  \
    \      }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\u542B\u307E\
    \u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n    int &ret =\
    \ dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n    for (int u\
    \ = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);\n  \
    \  }\n    return ret;\n}\n"
  code: "/*\n    0->1->2->3->0\u304C\u6700\u77ED\u3060\u3068\u3059\u308B\n    dp[{0,1,2,3}][0]->dp[{1,2,3}][3]\n\
    \    ->dp[{1,2}][2]->dp[{1}][1]->dp[{}][0]\n    inf\u306E\u5024\u3092\u8ABF\u6574\
    \u3057\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\
    \u306B\u3059\u308B\n    G->\u30D1\u30B9\u304C\u3042\u308C\u3070\u305D\u306E\u8DDD\
    \u96E2,\u306A\u3051\u308C\u3070INF\u3092\u3044\u308C\u308B\n*/\nint V, E;\nint\
    \ G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\n// \u30E1\u30E2\u5316\
    \u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n        if (v == 0)\
    \ {\n            return 0;\n        } else {\n            return inf / 3;\n  \
    \      }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\u542B\u307E\
    \u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n    int &ret =\
    \ dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n    for (int u\
    \ = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);\n  \
    \  }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/traveling-salesman-problem.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:35:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_2_A.test.cpp
documentation_of: dynamic-programming/traveling-salesman-problem.hpp
layout: document
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C(bitDP)"
---
