---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C.test.cpp
    title: test/AOJ/ALDS1_11_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bfs.hpp\"\nvector<int> BFS(const vector<vector<int>>\
    \ &G, int s) {\n    int N = (int)G.size();    // \u9802\u70B9\u6570\n    vector<int>\
    \ dist(N, -1);  // \u3059\u3079\u3066\u306E\u9802\u70B9\u3092\u672A\u8A2A\u554F\
    \u306B\u521D\u671F\u5316\n    queue<int> que;\n\n    // \u521D\u671F\u6761\u4EF6\
    \ (\u9802\u70B9s\u3092\u521D\u671F\u9802\u70B9\u3068\u3059\u308B)\n    dist[s]\
    \ = 0;\n    que.push(s);  // s\u3092\u63A2\u7D22\u6E08\u307F\u9802\u70B9\u306B\
    \n\n    // BFS\u958B\u59CB\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n\n        // \u9802\u70B9v\u304B\u3089\u305F\u3069\u308C\u308B\
    \u9802\u70B9\u3092\u5168\u3066\u8ABF\u3079\u308B\n        for (int x : G[v]) {\n\
    \            // \u3059\u3067\u306B\u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\
    \u63A2\u7D22\u3057\u306A\u3044\n            if (dist[x] != -1) continue;\n\n \
    \           // \u65B0\u305F\u306A\u672A\u63A2\u7D22\u9802\u70B9x\u306B\u3064\u3044\
    \u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\u3057\u3066\u30AD\u30E5\u30FC\
    \u306B\u633F\u5165\n            dist[x] = dist[v] + 1;\n            que.push(x);\n\
    \        }\n    }\n    return dist;\n}\n"
  code: "vector<int> BFS(const vector<vector<int>> &G, int s) {\n    int N = (int)G.size();\
    \    // \u9802\u70B9\u6570\n    vector<int> dist(N, -1);  // \u3059\u3079\u3066\
    \u306E\u9802\u70B9\u3092\u672A\u8A2A\u554F\u306B\u521D\u671F\u5316\n    queue<int>\
    \ que;\n\n    // \u521D\u671F\u6761\u4EF6 (\u9802\u70B9s\u3092\u521D\u671F\u9802\
    \u70B9\u3068\u3059\u308B)\n    dist[s] = 0;\n    que.push(s);  // s\u3092\u63A2\
    \u7D22\u6E08\u307F\u9802\u70B9\u306B\n\n    // BFS\u958B\u59CB\n    while (!que.empty())\
    \ {\n        int v = que.front();\n        que.pop();\n\n        // \u9802\u70B9\
    v\u304B\u3089\u305F\u3069\u308C\u308B\u9802\u70B9\u3092\u5168\u3066\u8ABF\u3079\
    \u308B\n        for (int x : G[v]) {\n            // \u3059\u3067\u306B\u767A\u898B\
    \u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\n         \
    \   if (dist[x] != -1) continue;\n\n            // \u65B0\u305F\u306A\u672A\u63A2\
    \u7D22\u9802\u70B9x\u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\
    \u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\u633F\u5165\n            dist[x] =\
    \ dist[v] + 1;\n            que.push(x);\n        }\n    }\n    return dist;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C.test.cpp
documentation_of: graph/bfs.hpp
layout: document
redirect_from:
- /library/graph/bfs.hpp
- /library/graph/bfs.hpp.html
title: graph/bfs.hpp
---