---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_3_C.test.cpp
    title: test/AOJ/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\nstruct SCC {\n    using Edge = int;\n \
    \   using SGraph = vector<vector<Edge>>;\n\n    // input\n    SGraph G, rG;\n\n\
    \    // result\n    vector<vector<int>> scc;\n    vector<int> cmp;\n    SGraph\
    \ dag;\n\n    // constructor\n    SCC(int N) : G(N), rG(N) {}\n\n    // add edge\n\
    \    void addedge(int u, int v) {\n        G[u].push_back(v);\n        rG[v].push_back(u);\n\
    \    }\n\n    // decomp\n    vector<bool> seen;\n    vector<int> vs, rvs;\n  \
    \  void dfs(int v) {\n        seen[v] = true;\n        for (auto e : G[v])\n \
    \           if (!seen[e]) dfs(e);\n        vs.push_back(v);\n    }\n    void rdfs(int\
    \ v, int k) {\n        seen[v] = true;\n        cmp[v] = k;\n        for (auto\
    \ e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n        rvs.push_back(v);\n\
    \    }\n\n    // reconstruct\n    set<pair<int, int>> newEdges;\n    void reconstruct()\
    \ {\n        int N = (int)G.size();\n        int dV = (int)scc.size();\n     \
    \   dag.assign(dV, vector<Edge>());\n        newEdges.clear();\n        for (int\
    \ i = 0; i < N; ++i) {\n            int u = cmp[i];\n            for (auto e :\
    \ G[i]) {\n                int v = cmp[e];\n                if (u == v) continue;\n\
    \                if (!newEdges.count({u, v})) {\n                    dag[u].push_back(v);\n\
    \                    newEdges.insert({u, v});\n                }\n           \
    \ }\n        }\n    }\n\n    // main\n    void solve() {\n        // first dfs\n\
    \        int N = (int)G.size();\n        seen.assign(N, false);\n        vs.clear();\n\
    \        for (int v = 0; v < N; ++v)\n            if (!seen[v]) dfs(v);\n\n  \
    \      // back dfs\n        int k = 0;\n        scc.clear();\n        cmp.assign(N,\
    \ -1);\n        seen.assign(N, false);\n        for (int i = N - 1; i >= 0; --i)\
    \ {\n            if (!seen[vs[i]]) {\n                rvs.clear();\n         \
    \       rdfs(vs[i], k++);\n                scc.push_back(rvs);\n            }\n\
    \        }\n\n        // reconstruct\n        reconstruct();\n    }\n};\n"
  code: "struct SCC {\n    using Edge = int;\n    using SGraph = vector<vector<Edge>>;\n\
    \n    // input\n    SGraph G, rG;\n\n    // result\n    vector<vector<int>> scc;\n\
    \    vector<int> cmp;\n    SGraph dag;\n\n    // constructor\n    SCC(int N) :\
    \ G(N), rG(N) {}\n\n    // add edge\n    void addedge(int u, int v) {\n      \
    \  G[u].push_back(v);\n        rG[v].push_back(u);\n    }\n\n    // decomp\n \
    \   vector<bool> seen;\n    vector<int> vs, rvs;\n    void dfs(int v) {\n    \
    \    seen[v] = true;\n        for (auto e : G[v])\n            if (!seen[e]) dfs(e);\n\
    \        vs.push_back(v);\n    }\n    void rdfs(int v, int k) {\n        seen[v]\
    \ = true;\n        cmp[v] = k;\n        for (auto e : rG[v])\n            if (!seen[e])\
    \ rdfs(e, k);\n        rvs.push_back(v);\n    }\n\n    // reconstruct\n    set<pair<int,\
    \ int>> newEdges;\n    void reconstruct() {\n        int N = (int)G.size();\n\
    \        int dV = (int)scc.size();\n        dag.assign(dV, vector<Edge>());\n\
    \        newEdges.clear();\n        for (int i = 0; i < N; ++i) {\n          \
    \  int u = cmp[i];\n            for (auto e : G[i]) {\n                int v =\
    \ cmp[e];\n                if (u == v) continue;\n                if (!newEdges.count({u,\
    \ v})) {\n                    dag[u].push_back(v);\n                    newEdges.insert({u,\
    \ v});\n                }\n            }\n        }\n    }\n\n    // main\n  \
    \  void solve() {\n        // first dfs\n        int N = (int)G.size();\n    \
    \    seen.assign(N, false);\n        vs.clear();\n        for (int v = 0; v <\
    \ N; ++v)\n            if (!seen[v]) dfs(v);\n\n        // back dfs\n        int\
    \ k = 0;\n        scc.clear();\n        cmp.assign(N, -1);\n        seen.assign(N,\
    \ false);\n        for (int i = N - 1; i >= 0; --i) {\n            if (!seen[vs[i]])\
    \ {\n                rvs.clear();\n                rdfs(vs[i], k++);\n       \
    \         scc.push_back(rvs);\n            }\n        }\n\n        // reconstruct\n\
    \        reconstruct();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2022-12-29 16:08:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_3_C.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(SCC)"
---
