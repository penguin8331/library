---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/diameter-weighted.hpp\"\nstruct Edge {\n    int to;\n\
    \    int cost;\n};\ntemplate <typename T>\npair<T, int> dfs(const vector<vector<Edge>>\
    \ &G, int u, int par) {  // \u6700\u9060\u70B9\u9593\u8DDD\u96E2\u3068\u6700\u9060\
    \u70B9\u3092\u6C42\u3081\u308B\n    pair<T, int> ret = make_pair((T)0, u);\n \
    \   for (auto e : G[u]) {\n        if (e.to == par) continue;\n        auto next\
    \ = dfs<T>(G, e.to, u);\n        next.first += e.cost;\n        ret = max(ret,\
    \ next);\n    }\n    return ret;\n}\ntemplate <typename T>\nT tree_diameter(const\
    \ vector<vector<Edge>> &G) {\n    pair<T, int> p = dfs<T>(G, 0, -1);\n    pair<T,\
    \ int> q = dfs<T>(G, p.second, -1);\n    return q.first;\n}\n"
  code: "struct Edge {\n    int to;\n    int cost;\n};\ntemplate <typename T>\npair<T,\
    \ int> dfs(const vector<vector<Edge>> &G, int u, int par) {  // \u6700\u9060\u70B9\
    \u9593\u8DDD\u96E2\u3068\u6700\u9060\u70B9\u3092\u6C42\u3081\u308B\n    pair<T,\
    \ int> ret = make_pair((T)0, u);\n    for (auto e : G[u]) {\n        if (e.to\
    \ == par) continue;\n        auto next = dfs<T>(G, e.to, u);\n        next.first\
    \ += e.cost;\n        ret = max(ret, next);\n    }\n    return ret;\n}\ntemplate\
    \ <typename T>\nT tree_diameter(const vector<vector<Edge>> &G) {\n    pair<T,\
    \ int> p = dfs<T>(G, 0, -1);\n    pair<T, int> q = dfs<T>(G, p.second, -1);\n\
    \    return q.first;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/diameter-weighted.hpp
  requiredBy: []
  timestamp: '2022-12-24 12:34:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_5_A.test.cpp
documentation_of: graph/diameter-weighted.hpp
layout: document
title: "\u6728\u306E\u76F4\u5F84"
---
