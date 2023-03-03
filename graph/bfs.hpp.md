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
    path: test/AOJ/ALDS1_11_C.test.cpp
    title: test/AOJ/ALDS1_11_C.test.cpp
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
    #line 7 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/bfs.hpp\"\
    \n\nvector<int> BFS(const vector<vector<int>> &G, int s) {\n    int N = (int)G.size();\
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
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nvector<int> BFS(const\
    \ vector<vector<int>> &G, int s) {\n    int N = (int)G.size();    // \u9802\u70B9\
    \u6570\n    vector<int> dist(N, -1);  // \u3059\u3079\u3066\u306E\u9802\u70B9\u3092\
    \u672A\u8A2A\u554F\u306B\u521D\u671F\u5316\n    queue<int> que;\n\n    // \u521D\
    \u671F\u6761\u4EF6 (\u9802\u70B9s\u3092\u521D\u671F\u9802\u70B9\u3068\u3059\u308B\
    )\n    dist[s] = 0;\n    que.push(s);  // s\u3092\u63A2\u7D22\u6E08\u307F\u9802\
    \u70B9\u306B\n\n    // BFS\u958B\u59CB\n    while (!que.empty()) {\n        int\
    \ v = que.front();\n        que.pop();\n\n        // \u9802\u70B9v\u304B\u3089\
    \u305F\u3069\u308C\u308B\u9802\u70B9\u3092\u5168\u3066\u8ABF\u3079\u308B\n   \
    \     for (int x : G[v]) {\n            // \u3059\u3067\u306B\u767A\u898B\u6E08\
    \u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\n            if (dist[x]\
    \ != -1) continue;\n\n            // \u65B0\u305F\u306A\u672A\u63A2\u7D22\u9802\
    \u70B9x\u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\u3057\
    \u3066\u30AD\u30E5\u30FC\u306B\u633F\u5165\n            dist[x] = dist[v] + 1;\n\
    \            que.push(x);\n        }\n    }\n    return dist;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: graph/bfs.hpp
  requiredBy: []
  timestamp: '2023-03-03 16:10:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C.test.cpp
documentation_of: graph/bfs.hpp
layout: document
title: BFS
---
