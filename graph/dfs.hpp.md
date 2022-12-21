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
  bundledCode: "#line 1 \"graph/dfs.hpp\"\nvector<bool> seen;\nvoid dfs(const vector<vector<int>>&\
    \ G, int v) {\n    seen[v] = true;\n\n    // v\u304B\u3089\u884C\u3051\u308B\u5404\
    \u9802\u70B9 next_v \u306B\u3064\u3044\u3066\n    for (auto next_v : G[v]) {\n\
    \        if (seen[next_v]) continue;  //\u63A2\u7D22\u6E08\u307F\u306A\u3089\u635C\
    \u7D22\u3057\u306A\u3044\n        dfs(G, next_v);\n    }\n}\n"
  code: "vector<bool> seen;\nvoid dfs(const vector<vector<int>>& G, int v) {\n   \
    \ seen[v] = true;\n\n    // v\u304B\u3089\u884C\u3051\u308B\u5404\u9802\u70B9\
    \ next_v \u306B\u3064\u3044\u3066\n    for (auto next_v : G[v]) {\n        if\
    \ (seen[next_v]) continue;  //\u63A2\u7D22\u6E08\u307F\u306A\u3089\u635C\u7D22\
    \u3057\u306A\u3044\n        dfs(G, next_v);\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dfs.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dfs.hpp
layout: document
title: "\u6DF1\u3055\u512A\u5148\u5EA6\u63A2\u7D22"
---
