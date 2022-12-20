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
  bundledCode: "#line 1 \"GraphTheory/Dijkstra.hpp\"\nstruct Edge {\n    long long\
    \ to;\n    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
    \ &G, int s) {\n    int N = G.size();\n    vector<long long> dis(N, INF);\n  \
    \  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long\
    \ long, int>>> pq;  // \u300C\u4EEE\u306E\u6700\u77ED\u8DDD\u96E2, \u9802\u70B9\
    \u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n    dis[s] = 0;\n    pq.emplace(dis[s],\
    \ s);\n    while (!pq.empty()) {\n        pair<long long, int> p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (dis[v] < p.first) {\
    \  // \u6700\u77ED\u8DDD\u96E2\u3067\u7121\u3051\u308C\u3070\u7121\u8996\n   \
    \         continue;\n        }\n        for (auto &e : G[v]) {\n            if\
    \ (dis[e.to] > dis[v] + e.cost) {  // \u6700\u77ED\u8DDD\u96E2\u5019\u88DC\u306A\
    \u3089 priority_queue \u306B\u8FFD\u52A0\n                dis[e.to] = dis[v] +\
    \ e.cost;\n                pq.emplace(dis[e.to], e.to);\n            }\n     \
    \   }\n    }\n}\n"
  code: "struct Edge {\n    long long to;\n    long long cost;\n};\nvector<long long>\
    \ dijkstra(const vector<vector<Edge>> &G, int s) {\n    int N = G.size();\n  \
    \  vector<long long> dis(N, INF);\n    priority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>, greater<pair<long long, int>>> pq;  // \u300C\u4EEE\u306E\u6700\
    \u77ED\u8DDD\u96E2, \u9802\u70B9\u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\
    \u3076\n    dis[s] = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n\
    \        pair<long long, int> p = pq.top();\n        pq.pop();\n        int v\
    \ = p.second;\n        if (dis[v] < p.first) {  // \u6700\u77ED\u8DDD\u96E2\u3067\
    \u7121\u3051\u308C\u3070\u7121\u8996\n            continue;\n        }\n     \
    \   for (auto &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {  //\
    \ \u6700\u77ED\u8DDD\u96E2\u5019\u88DC\u306A\u3089 priority_queue \u306B\u8FFD\
    \u52A0\n                dis[e.to] = dis[v] + e.cost;\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/Dijkstra.hpp
  requiredBy: []
  timestamp: '2022-12-20 15:08:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: GraphTheory/Dijkstra.hpp
layout: document
redirect_from:
- /library/GraphTheory/Dijkstra.hpp
- /library/GraphTheory/Dijkstra.hpp.html
title: GraphTheory/Dijkstra.hpp
---
