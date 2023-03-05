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
    path: test/AOJ/GRL_3_C.test.cpp
    title: test/AOJ/GRL_3_C.test.cpp
  - icon: ':x:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    using namespace std;\n#line 3 \"graph/scc.hpp\"\n\nstruct SCC {\n    using Edge\
    \ = int;\n    using SGraph = vector<vector<Edge>>;\n\n    // input\n    SGraph\
    \ G, rG;\n\n    // result\n    vector<vector<int>> scc;\n    vector<int> cmp;\n\
    \    SGraph dag;\n\n    // constructor\n    SCC(int N) : G(N), rG(N) {}\n\n  \
    \  // add edge\n    void addedge(int u, int v) {\n        G[u].push_back(v);\n\
    \        rG[v].push_back(u);\n    }\n\n    // decomp\n    vector<bool> seen;\n\
    \    vector<int> vs, rvs;\n    void dfs(int v) {\n        seen[v] = true;\n  \
    \      for (auto e : G[v])\n            if (!seen[e]) dfs(e);\n        vs.push_back(v);\n\
    \    }\n    void rdfs(int v, int k) {\n        seen[v] = true;\n        cmp[v]\
    \ = k;\n        for (auto e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n\
    \        rvs.push_back(v);\n    }\n\n    // reconstruct\n    set<pair<int, int>>\
    \ newEdges;\n    void reconstruct() {\n        int N = (int)G.size();\n      \
    \  int dV = (int)scc.size();\n        dag.assign(dV, vector<Edge>());\n      \
    \  newEdges.clear();\n        for (int i = 0; i < N; ++i) {\n            int u\
    \ = cmp[i];\n            for (auto e : G[i]) {\n                int v = cmp[e];\n\
    \                if (u == v) continue;\n                if (!newEdges.count({u,\
    \ v})) {\n                    dag[u].push_back(v);\n                    newEdges.insert({u,\
    \ v});\n                }\n            }\n        }\n    }\n\n    // main\n  \
    \  void solve() {\n        // first dfs\n        int N = (int)G.size();\n    \
    \    seen.assign(N, false);\n        vs.clear();\n        for (int v = 0; v <\
    \ N; ++v)\n            if (!seen[v]) dfs(v);\n\n        // back dfs\n        int\
    \ k = 0;\n        scc.clear();\n        cmp.assign(N, -1);\n        seen.assign(N,\
    \ false);\n        for (int i = N - 1; i >= 0; --i) {\n            if (!seen[vs[i]])\
    \ {\n                rvs.clear();\n                rdfs(vs[i], k++);\n       \
    \         scc.push_back(rvs);\n            }\n        }\n\n        // reconstruct\n\
    \        reconstruct();\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct SCC {\n   \
    \ using Edge = int;\n    using SGraph = vector<vector<Edge>>;\n\n    // input\n\
    \    SGraph G, rG;\n\n    // result\n    vector<vector<int>> scc;\n    vector<int>\
    \ cmp;\n    SGraph dag;\n\n    // constructor\n    SCC(int N) : G(N), rG(N) {}\n\
    \n    // add edge\n    void addedge(int u, int v) {\n        G[u].push_back(v);\n\
    \        rG[v].push_back(u);\n    }\n\n    // decomp\n    vector<bool> seen;\n\
    \    vector<int> vs, rvs;\n    void dfs(int v) {\n        seen[v] = true;\n  \
    \      for (auto e : G[v])\n            if (!seen[e]) dfs(e);\n        vs.push_back(v);\n\
    \    }\n    void rdfs(int v, int k) {\n        seen[v] = true;\n        cmp[v]\
    \ = k;\n        for (auto e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n\
    \        rvs.push_back(v);\n    }\n\n    // reconstruct\n    set<pair<int, int>>\
    \ newEdges;\n    void reconstruct() {\n        int N = (int)G.size();\n      \
    \  int dV = (int)scc.size();\n        dag.assign(dV, vector<Edge>());\n      \
    \  newEdges.clear();\n        for (int i = 0; i < N; ++i) {\n            int u\
    \ = cmp[i];\n            for (auto e : G[i]) {\n                int v = cmp[e];\n\
    \                if (u == v) continue;\n                if (!newEdges.count({u,\
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
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/scc.test.cpp
  - test/AOJ/GRL_3_C.test.cpp
documentation_of: graph/scc.hpp
layout: document
title: Strongly Connected Component
---

## グラフの設計

- `SCC scc(N)` : 頂点数 `N` のグラフを宣言
- `addedge(int u,int v)` : 頂点 `u` から `v` にかけて有向辺を張る

## 強連結成分分解

- `solve()` : いままで設計されたグラフを用いて強連結成分分解する  
結果は以下の要素に格納される
  - `scc[i]` : トポロジカルソートして `i` 個目となる連結成分となる頂点
  - `cmp[i]` : 頂点 `i` が `scc` の何個目の連結成分に属するか
