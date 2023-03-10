---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
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
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#define line\n#endif\n#line 8 \"template/template.hpp\"\n\
    using namespace std;\n#line 3 \"dynamic-programming/traveling-salesman-problem.hpp\"\
    \n\nint V, E;\nint G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\nconst\
    \ int maxi = inf / 3;\n// \u30E1\u30E2\u5316\u518D\u5E30\nint rec(int S, int v)\
    \ {\n    if (S == 0) {\n        if (v == 0) {\n            return 0;\n       \
    \ } else {\n            return inf / 3;\n        }\n    }\n    if ((S & (1 <<\
    \ v)) == 0) {  // S\u306B{v}\u304C\u542B\u307E\u308C\u3066\u3044\u306A\u3044\n\
    \        return inf / 3;\n    }\n    int& ret = dp[S][v];\n    if (ret != 0) return\
    \ ret;\n    ret = inf / 3;\n    for (int u = 0; u < V; u++) {\n        chmin(ret,\
    \ rec(S ^ (1 << v), u) + G[u][v]);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nint V, E;\nint G[20][20];\
    \  // \u30B0\u30E9\u30D5\nint dp[50000][20];\nconst int maxi = inf / 3;\n// \u30E1\
    \u30E2\u5316\u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n       \
    \ if (v == 0) {\n            return 0;\n        } else {\n            return inf\
    \ / 3;\n        }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\u542B\
    \u307E\u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n    int&\
    \ ret = dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n    for\
    \ (int u = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: dynamic-programming/traveling-salesman-problem.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_2_A.test.cpp
documentation_of: dynamic-programming/traveling-salesman-problem.hpp
layout: document
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (by bitDP)"
---

## 使い方

`dp[S][i]` = `S` を周って `i` に着くような経路の最短の長さ

`G` -> パスがあればその距離、なければ `INF` をいれる (オーバーフローしないように注意)
