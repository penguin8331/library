---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
    path: test/yosupo/shortes-path.test.cpp
    title: test/yosupo/shortes-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/dijkstra-route.hpp\"\n\nstruct Edge {\n    long long to;\n\
    \    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
    \ &G, int s, vector<int> &prev) {\n    int N = G.size();\n    vector<long long>\
    \ dis(N, INF);\n    prev.assign(N, -1);\n    priority_queue<pair<long long, int>,\
    \ vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n    dis[s]\
    \ = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n        pair<long\
    \ long, int> p = pq.top();\n        pq.pop();\n        int v = p.second;\n   \
    \     if (dis[v] < p.first) {\n            continue;\n        }\n        for (auto\
    \ &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {\n             \
    \   dis[e.to] = dis[v] + e.cost;\n                prev[e.to] = v;\n          \
    \      pq.emplace(dis[e.to], e.to);\n            }\n        }\n    }\n    return\
    \ dis;\n}\nvector<int> get_path(const vector<int> &prev, int t) {\n    vector<int>\
    \ path;\n    for (int cur = t; cur != -1; cur = prev[cur]) {\n        path.push_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());\n    return path;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Edge {\n  \
    \  long long to;\n    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
    \ &G, int s, vector<int> &prev) {\n    int N = G.size();\n    vector<long long>\
    \ dis(N, INF);\n    prev.assign(N, -1);\n    priority_queue<pair<long long, int>,\
    \ vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n    dis[s]\
    \ = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n        pair<long\
    \ long, int> p = pq.top();\n        pq.pop();\n        int v = p.second;\n   \
    \     if (dis[v] < p.first) {\n            continue;\n        }\n        for (auto\
    \ &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {\n             \
    \   dis[e.to] = dis[v] + e.cost;\n                prev[e.to] = v;\n          \
    \      pq.emplace(dis[e.to], e.to);\n            }\n        }\n    }\n    return\
    \ dis;\n}\nvector<int> get_path(const vector<int> &prev, int t) {\n    vector<int>\
    \ path;\n    for (int cur = t; cur != -1; cur = prev[cur]) {\n        path.push_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/dijkstra-route.hpp
  requiredBy: []
  timestamp: '2023-04-21 23:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortes-path.test.cpp
documentation_of: graph/dijkstra-route.hpp
layout: document
title: "Dijkstra (\u7D4C\u8DEF\u5FA9\u5143\u3042\u308A)"
---

## 使い方

- `dijkstra(vector<vector<Edge>> G,int s,vector<int> prev)`

    入力：グラフ `G`, 開始点 `s`, 最短経路の前の点を記録する `prev`

    出力: 開始点 `s` から各頂点への最短距離

    計算量：$O(E log V)$

    副作用：`prev` が書き換えられる

- `getpath(prev, t)`

    入力：`dijkstra` で得た `prev`, ゴール `t`

    出力: `s` から `t` への最短路のパス
