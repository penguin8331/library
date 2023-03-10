---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
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
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#define line\n#endif\n#line 8 \"template/template.hpp\"\n\
    using namespace std;\n#line 3 \"graph/dijkstra.hpp\"\n\nstruct Edge {\n    long\
    \ long to;\n    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
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
    \   }\n    }\n    return dis;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Edge {\n  \
    \  long long to;\n    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
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
    \   }\n    }\n    return dis;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: Dijkstra
---
