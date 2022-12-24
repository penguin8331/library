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
  bundledCode: "#line 1 \"graph/dijkstra2d.hpp\"\nint H, W;\nvector<vector<char>>\
    \ G;\nvoid dijkstra(pair<int, int> s, vector<vector<long long>>& dis) {\n    dis.resize(H,\
    \ vector<long long>(W, INF));\n    priority_queue<pair<long long, pair<int, int>>,\
    \ vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>>\
    \ pq;  // \u300C\u4EEE\u306E\u6700\u77ED\u8DDD\u96E2, \u9802\u70B9\u300D\u304C\
    \u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n    dis[s.first][s.second] = 0;\n\
    \    pq.emplace(dis[s.first][s.second], s);\n    while (!pq.empty()) {\n     \
    \   auto p = pq.top();\n        pq.pop();\n        auto v = p.second;\n      \
    \  if (dis[v.first][v.second] < p.first) {  // \u6700\u77ED\u8DDD\u96E2\u3067\u7121\
    \u3051\u308C\u3070\u7121\u8996\n            continue;\n        }\n        for\
    \ (int i = 0; i < 4; i++) {\n            int X = v.first + dx[i];\n          \
    \  int Y = v.second + dy[i];\n            if (X < 0 || X >= H || Y < 0 || Y >=\
    \ W) continue;\n            int cost = dis[v.first][v.second] + (G[X][Y] == '#'\
    \ ? 1 : 0);\n            if (dis[X][Y] > cost) {  // \u6700\u77ED\u8DDD\u96E2\u5019\
    \u88DC\u306A\u3089 priority_queue \u306B\u8FFD\u52A0\n                dis[X][Y]\
    \ = cost;\n                pq.emplace(dis[X][Y], pair<int, int>(X, Y));\n    \
    \        }\n        }\n    }\n}\n"
  code: "int H, W;\nvector<vector<char>> G;\nvoid dijkstra(pair<int, int> s, vector<vector<long\
    \ long>>& dis) {\n    dis.resize(H, vector<long long>(W, INF));\n    priority_queue<pair<long\
    \ long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long\
    \ long, pair<int, int>>>> pq;  // \u300C\u4EEE\u306E\u6700\u77ED\u8DDD\u96E2,\
    \ \u9802\u70B9\u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n    dis[s.first][s.second]\
    \ = 0;\n    pq.emplace(dis[s.first][s.second], s);\n    while (!pq.empty()) {\n\
    \        auto p = pq.top();\n        pq.pop();\n        auto v = p.second;\n \
    \       if (dis[v.first][v.second] < p.first) {  // \u6700\u77ED\u8DDD\u96E2\u3067\
    \u7121\u3051\u308C\u3070\u7121\u8996\n            continue;\n        }\n     \
    \   for (int i = 0; i < 4; i++) {\n            int X = v.first + dx[i];\n    \
    \        int Y = v.second + dy[i];\n            if (X < 0 || X >= H || Y < 0 ||\
    \ Y >= W) continue;\n            int cost = dis[v.first][v.second] + (G[X][Y]\
    \ == '#' ? 1 : 0);\n            if (dis[X][Y] > cost) {  // \u6700\u77ED\u8DDD\
    \u96E2\u5019\u88DC\u306A\u3089 priority_queue \u306B\u8FFD\u52A0\n           \
    \     dis[X][Y] = cost;\n                pq.emplace(dis[X][Y], pair<int, int>(X,\
    \ Y));\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra2d.hpp
  requiredBy: []
  timestamp: '2022-12-24 10:49:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra2d.hpp
layout: document
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u30B0\u30EA\u30C3\u30C9)"
---
