---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_12_A.test.cpp
    title: test/AOJ/ALDS1_12_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9\
    \ + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T&\
    \ a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename\
    \ T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false));\
    \ }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n    \
    \    std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n     \
    \   std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/prim.hpp\"\n\
    \nstruct Edge {\n    int to;\n    long long cost;\n};\nstruct Prim {\n    vector<vector<Edge>>\
    \ G;\n    int V;\n    long long sum;\n    Prim(vector<vector<Edge>> &G_, int V_)\
    \ : G(G_), V(V_) {\n        sum = 0;\n        vector<bool> seen(V, false);\n \
    \       priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,\
    \ int>>> pq;\n        pq.push(mp(0, 0));\n        while (!pq.empty()) {\n    \
    \        auto p = pq.top();\n            pq.pop();\n            if (seen[p.second])\
    \ continue;\n            seen[p.second] = true;\n            sum += p.first;\n\
    \            for (const auto &i : G[p.second]) {\n                pq.push(mp(i.cost,\
    \ i.to));\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"template/template.hpp\"\n\nstruct Edge {\n    int\
    \ to;\n    long long cost;\n};\nstruct Prim {\n    vector<vector<Edge>> G;\n \
    \   int V;\n    long long sum;\n    Prim(vector<vector<Edge>> &G_, int V_) : G(G_),\
    \ V(V_) {\n        sum = 0;\n        vector<bool> seen(V, false);\n        priority_queue<pair<ll,\
    \ int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;\n        pq.push(mp(0,\
    \ 0));\n        while (!pq.empty()) {\n            auto p = pq.top();\n      \
    \      pq.pop();\n            if (seen[p.second]) continue;\n            seen[p.second]\
    \ = true;\n            sum += p.first;\n            for (const auto &i : G[p.second])\
    \ {\n                pq.push(mp(i.cost, i.to));\n            }\n        }\n  \
    \  }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: graph/prim.hpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_12_A.test.cpp
documentation_of: graph/prim.hpp
layout: document
title: "Prim (\u6700\u5C0F\u5168\u57DF\u6728) $O(V log E)$"
---
