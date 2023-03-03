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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/bfs2d.hpp\"\
    \n\nvector<vector<int>> BFS(int H, int W, const vector<string> &G, pair<int, int>\
    \ s) {\n    vector<vector<int>> dist(H, vector<int>(W, -1));  //\u3059\u3079\u3066\
    \u306E\u9802\u70B9\u3092\u672A\u8A2A\u554F\u306B\u521D\u671F\u5316\n    queue<pair<int,\
    \ int>> que;\n\n    //\u521D\u671F\u6761\u4EF6 (\u9802\u70B9s\u3092\u521D\u671F\
    \u9802\u70B9\u3068\u3059\u308B)\n    dist[s.first][s.second] = 0;\n    que.push(s);\
    \  // s\u3092\u63A2\u7D22\u6E08\u307F\u9802\u70B9\u306B\n\n    // BFS\u958B\u59CB\
    \n    while (!que.empty()) {\n        pair<int, int> v = que.front();\n      \
    \  que.pop();\n\n        //\u9802\u70B9v\u304B\u3089\u305F\u3069\u308C\u308B\u9802\
    \u70B9\u3092\u5168\u3066\u8ABF\u3079\u308B\n        for (int i = 0; i < 4; i++)\
    \ {\n            int X = dx[i] + v.first;\n            int Y = dy[i] + v.second;\n\
    \            if (X < 0 || X >= H || Y < 0 || Y >= W) continue;\n            //\u3059\
    \u3067\u306B\u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\
    \u306A\u3044\n            if (dist[X][Y] != -1 || G[X][Y] == '#') continue;\n\n\
    \            //\u65B0\u305F\u306A\u672A\u63A2\u7D22\u70B9x\u306B\u3064\u3044\u3066\
    \u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\
    \u633F\u5165\n            dist[X][Y] = dist[v.first][v.second] + 1;\n        \
    \    que.push(make_pair(X, Y));\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include \"template/template.hpp\"\n\nvector<vector<int>> BFS(int\
    \ H, int W, const vector<string> &G, pair<int, int> s) {\n    vector<vector<int>>\
    \ dist(H, vector<int>(W, -1));  //\u3059\u3079\u3066\u306E\u9802\u70B9\u3092\u672A\
    \u8A2A\u554F\u306B\u521D\u671F\u5316\n    queue<pair<int, int>> que;\n\n    //\u521D\
    \u671F\u6761\u4EF6 (\u9802\u70B9s\u3092\u521D\u671F\u9802\u70B9\u3068\u3059\u308B\
    )\n    dist[s.first][s.second] = 0;\n    que.push(s);  // s\u3092\u63A2\u7D22\u6E08\
    \u307F\u9802\u70B9\u306B\n\n    // BFS\u958B\u59CB\n    while (!que.empty()) {\n\
    \        pair<int, int> v = que.front();\n        que.pop();\n\n        //\u9802\
    \u70B9v\u304B\u3089\u305F\u3069\u308C\u308B\u9802\u70B9\u3092\u5168\u3066\u8ABF\
    \u3079\u308B\n        for (int i = 0; i < 4; i++) {\n            int X = dx[i]\
    \ + v.first;\n            int Y = dy[i] + v.second;\n            if (X < 0 ||\
    \ X >= H || Y < 0 || Y >= W) continue;\n            //\u3059\u3067\u306B\u767A\
    \u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\n   \
    \         if (dist[X][Y] != -1 || G[X][Y] == '#') continue;\n\n            //\u65B0\
    \u305F\u306A\u672A\u63A2\u7D22\u70B9x\u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\
    \u5831\u3092\u66F4\u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\u633F\u5165\n   \
    \         dist[X][Y] = dist[v.first][v.second] + 1;\n            que.push(make_pair(X,\
    \ Y));\n        }\n    }\n    return dist;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: graph/bfs2d.hpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfs2d.hpp
layout: document
title: BFS-2D
---
