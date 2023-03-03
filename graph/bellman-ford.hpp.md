---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
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
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/bellman-ford.hpp\"\
    \n\nstruct Edge {\n    long long from;\n    long long to;\n    long long cost;\n\
    };\nbool bellman_ford(const vector<Edge> &Es, int V, int s, vector<long long>\
    \ &dis) {\n    dis.assign(V, INF);\n    dis[s] = 0;\n    int cnt = 0;\n    while\
    \ (cnt < V) {\n        bool end = true;\n        for (auto e : Es) {\n       \
    \     if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {\n        \
    \        dis[e.to] = dis[e.from] + e.cost;\n                end = false;\n   \
    \         }\n        }\n        if (end) break;\n        cnt++;\n    }\n    return\
    \ (cnt == V);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Edge {\n  \
    \  long long from;\n    long long to;\n    long long cost;\n};\nbool bellman_ford(const\
    \ vector<Edge> &Es, int V, int s, vector<long long> &dis) {\n    dis.assign(V,\
    \ INF);\n    dis[s] = 0;\n    int cnt = 0;\n    while (cnt < V) {\n        bool\
    \ end = true;\n        for (auto e : Es) {\n            if (dis[e.from] != INF\
    \ && dis[e.from] + e.cost < dis[e.to]) {\n                dis[e.to] = dis[e.from]\
    \ + e.cost;\n                end = false;\n            }\n        }\n        if\
    \ (end) break;\n        cnt++;\n    }\n    return (cnt == V);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
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
