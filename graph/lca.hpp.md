---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_C.test.cpp
    title: test/AOJ/GRL_5_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.hpp\"\nstruct LCA {\n    vector<vector<int>> parent;\
    \  // parent[d][v] := 2^d-th parent of v\n    vector<int> depth;\n    LCA() {}\n\
    \    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n    void init(const\
    \ vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V,\
    \ -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for\
    \ (int i = 0; i + 1 < (int)parent.size(); ++i)\n            for (int v = 0; v\
    \ < V; ++v)\n                if (parent[i][v] != -1)\n                    parent[i\
    \ + 1][v] = parent[i][parent[i][v]];\n    }\n    void dfs(const vector<vector<int>>&\
    \ G, int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n\
    \        for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n \
    \   }\n    int after(int u, int k) {\n        for (int i = 0; i < (int)parent.size();\
    \ i++) {\n            if (k & (1 << i)) {\n                u = parent[i][u];\n\
    \            }\n        }\n        return u;\n    }\n    int get(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) swap(u, v);\n        v = after(v, depth[v]\
    \ - depth[u]);\n        if (u == v) return u;\n        for (int i = (int)parent.size()\
    \ - 1; i >= 0; --i) {\n            if (parent[i][u] != parent[i][v]) {\n     \
    \           u = parent[i][u];\n                v = parent[i][v];\n           \
    \ }\n        }\n        return parent[0][u];\n    }\n    int dist(int u, int v)\
    \ {\n        return depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool\
    \ is_on_path(int u, int v, int a) {\n        return dist(u, a) + dist(a, v) ==\
    \ dist(u, v);\n    }\n};\n"
  code: "struct LCA {\n    vector<vector<int>> parent;  // parent[d][v] := 2^d-th\
    \ parent of v\n    vector<int> depth;\n    LCA() {}\n    LCA(const vector<vector<int>>&\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2023-01-30 18:54:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_5_C.test.cpp
documentation_of: graph/lca.hpp
layout: document
title: Lowest Common Ancestor
---
