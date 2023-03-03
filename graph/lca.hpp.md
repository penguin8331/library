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
    path: test/AOJ/GRL_5_C.test.cpp
    title: test/AOJ/GRL_5_C.test.cpp
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
    #line 7 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/lca.hpp\"\
    \n\nstruct LCA {\n    vector<vector<int>> parent;  // parent[d][v] := 2^d-th parent\
    \ of v\n    vector<int> depth;\n    LCA() {}\n    LCA(const vector<vector<int>>&\
    \ G, int r = 0) { init(G, r); }\n    void init(const vector<vector<int>>& G, int\
    \ r = 0) {\n        int V = (int)G.size();\n        int h = 1;\n        while\
    \ ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V, -1));\n       \
    \ depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for (int i = 0; i +\
    \ 1 < (int)parent.size(); ++i)\n            for (int v = 0; v < V; ++v)\n    \
    \            if (parent[i][v] != -1)\n                    parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \    }\n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n  \
    \      parent[0][v] = p;\n        depth[v] = d;\n        for (auto e : G[v])\n\
    \            if (e != p) dfs(G, e, v, d + 1);\n    }\n    int after(int u, int\
    \ k) {\n        for (int i = 0; i < (int)parent.size(); i++) {\n            if\
    \ (k & (1 << i)) {\n                u = parent[i][u];\n            }\n       \
    \ }\n        return u;\n    }\n    int get(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        v = after(v, depth[v] - depth[u]);\n      \
    \  if (u == v) return u;\n        for (int i = (int)parent.size() - 1; i >= 0;\
    \ --i) {\n            if (parent[i][u] != parent[i][v]) {\n                u =\
    \ parent[i][u];\n                v = parent[i][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int dist(int u, int v) {\n        return\
    \ depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool is_on_path(int\
    \ u, int v, int a) {\n        return dist(u, a) + dist(a, v) == dist(u, v);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct LCA {\n   \
    \ vector<vector<int>> parent;  // parent[d][v] := 2^d-th parent of v\n    vector<int>\
    \ depth;\n    LCA() {}\n    LCA(const vector<vector<int>>& G, int r = 0) { init(G,\
    \ r); }\n    void init(const vector<vector<int>>& G, int r = 0) {\n        int\
    \ V = (int)G.size();\n        int h = 1;\n        while ((1 << h) < V) ++h;\n\
    \        parent.assign(h, vector<int>(V, -1));\n        depth.assign(V, -1);\n\
    \        dfs(G, r, -1, 0);\n        for (int i = 0; i + 1 < (int)parent.size();\
    \ ++i)\n            for (int v = 0; v < V; ++v)\n                if (parent[i][v]\
    \ != -1)\n                    parent[i + 1][v] = parent[i][parent[i][v]];\n  \
    \  }\n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n    \
    \    parent[0][v] = p;\n        depth[v] = d;\n        for (auto e : G[v])\n \
    \           if (e != p) dfs(G, e, v, d + 1);\n    }\n    int after(int u, int\
    \ k) {\n        for (int i = 0; i < (int)parent.size(); i++) {\n            if\
    \ (k & (1 << i)) {\n                u = parent[i][u];\n            }\n       \
    \ }\n        return u;\n    }\n    int get(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        v = after(v, depth[v] - depth[u]);\n      \
    \  if (u == v) return u;\n        for (int i = (int)parent.size() - 1; i >= 0;\
    \ --i) {\n            if (parent[i][u] != parent[i][v]) {\n                u =\
    \ parent[i][u];\n                v = parent[i][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int dist(int u, int v) {\n        return\
    \ depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool is_on_path(int\
    \ u, int v, int a) {\n        return dist(u, a) + dist(a, v) == dist(u, v);\n\
    \    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2023-03-03 16:10:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_C.test.cpp
documentation_of: graph/lca.hpp
layout: document
title: Lowest Common Ancestor
---
