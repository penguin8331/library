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
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/two-sat.hpp
    title: graph/two-sat.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_3_C.test.cpp
    title: test/AOJ/GRL_3_C.test.cpp
  - icon: ':x:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':x:'
    path: test/yosupo/two-sat.test.cpp
    title: test/yosupo/two-sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct SCC {\n   \
    \ using Edge = int;\n    using SGraph = vector<vector<Edge>>;\n\n    SGraph G,\
    \ rG;\n\n    vector<vector<int>> scc;\n    vector<int> cmp;\n    SGraph dag;\n\
    \n    explicit SCC(int N) : G(N), rG(N) {}\n\n    void addedge(int u, int v) {\n\
    \        G[u].push_back(v);\n        rG[v].push_back(u);\n    }\n\n    vector<bool>\
    \ seen;\n    vector<int> vs, rvs;\n    void dfs(int v) {\n        seen[v] = true;\n\
    \        for (auto e : G[v])\n            if (!seen[e]) dfs(e);\n        vs.push_back(v);\n\
    \    }\n    void rdfs(int v, int k) {\n        seen[v] = true;\n        cmp[v]\
    \ = k;\n        for (auto e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n\
    \        rvs.push_back(v);\n    }\n\n    set<pair<int, int>> newEdges;\n    void\
    \ reconstruct() {\n        int N = (int)G.size();\n        int dV = (int)scc.size();\n\
    \        dag.assign(dV, vector<Edge>());\n        newEdges.clear();\n        for\
    \ (int i = 0; i < N; ++i) {\n            int u = cmp[i];\n            for (auto\
    \ e : G[i]) {\n                int v = cmp[e];\n                if (u == v) continue;\n\
    \                if (!newEdges.count({u, v})) {\n                    dag[u].push_back(v);\n\
    \                    newEdges.insert({u, v});\n                }\n           \
    \ }\n        }\n    }\n\n    void solve() {\n        int N = (int)G.size();\n\
    \        seen.assign(N, false);\n        vs.clear();\n        for (int v = 0;\
    \ v < N; ++v)\n            if (!seen[v]) dfs(v);\n\n        int k = 0;\n     \
    \   scc.clear();\n        cmp.assign(N, -1);\n        seen.assign(N, false);\n\
    \        for (int i = N - 1; i >= 0; --i) {\n            if (!seen[vs[i]]) {\n\
    \                rvs.clear();\n                rdfs(vs[i], k++);\n           \
    \     scc.push_back(rvs);\n            }\n        }\n\n        reconstruct();\n\
    \    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy:
  - graph/two-sat.hpp
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_3_C.test.cpp
  - test/yosupo/scc.test.cpp
  - test/yosupo/two-sat.test.cpp
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
