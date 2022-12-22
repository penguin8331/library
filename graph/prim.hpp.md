---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_12_A.test.cpp
    title: test/AOJ/ALDS1_12_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/prim.hpp\"\nstruct Edge {\n    int to;\n    long long\
    \ cost;\n};\nstruct Prim {\n    vector<vector<Edge>> G;\n    int V;\n    long\
    \ long sum;\n    Prim(vector<vector<Edge>> &G_, int V_) : G(G_), V(V_) {\n   \
    \     sum = 0;\n        vector<bool> seen(V, false);\n        priority_queue<pair<ll,\
    \ int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;\n        pq.push(mp(0,\
    \ 0));\n        while (!pq.empty()) {\n            auto p = pq.top();\n      \
    \      pq.pop();\n            if (seen[p.second]) continue;\n            seen[p.second]\
    \ = true;\n            sum += p.first;\n            for (const auto &i : G[p.second])\
    \ {\n                pq.push(mp(i.cost, i.to));\n            }\n        }\n  \
    \  }\n};\n"
  code: "struct Edge {\n    int to;\n    long long cost;\n};\nstruct Prim {\n    vector<vector<Edge>>\
    \ G;\n    int V;\n    long long sum;\n    Prim(vector<vector<Edge>> &G_, int V_)\
    \ : G(G_), V(V_) {\n        sum = 0;\n        vector<bool> seen(V, false);\n \
    \       priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,\
    \ int>>> pq;\n        pq.push(mp(0, 0));\n        while (!pq.empty()) {\n    \
    \        auto p = pq.top();\n            pq.pop();\n            if (seen[p.second])\
    \ continue;\n            seen[p.second] = true;\n            sum += p.first;\n\
    \            for (const auto &i : G[p.second]) {\n                pq.push(mp(i.cost,\
    \ i.to));\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/prim.hpp
  requiredBy: []
  timestamp: '2022-12-22 10:38:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_12_A.test.cpp
documentation_of: graph/prim.hpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6728(\u30D7\u30EA\u30E0) $O(V log E)$"
---
