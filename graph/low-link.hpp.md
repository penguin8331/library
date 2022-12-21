---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_3_A.test.cpp
    title: test/AOJ/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_3_B.test.cpp
    title: test/AOJ/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/low-link.hpp\"\nstruct LowLink {\n    // main results\n\
    \    vector<int> aps;             // articulation points\n    vector<pair<int,\
    \ int>> brs;  // brideges\n\n    // intermediate results\n    vector<int> seen,\
    \ ord, low;\n    void dfs_lowlink(const vector<vector<int>> &G, int v, int p =\
    \ -1) {\n        static int time = 0;\n        seen[v] = true;\n        ord[v]\
    \ = low[v] = time++;\n        int num_of_child = 0;\n        bool exist = false;\
    \  // for articulation point\n        for (auto ch : G[v]) {\n            if (seen[ch])\
    \ {\n                if (ch != p) low[v] = min(low[v], ord[ch]);  // back edge\n\
    \                continue;\n            }\n            dfs_lowlink(G, ch, v);\n\
    \            low[v] = min(low[v], low[ch]);  // forward edge of DFS-tree\n   \
    \         if (ord[v] < low[ch]) brs.emplace_back(v, ch);\n            if (ord[v]\
    \ <= low[ch]) exist = true;\n            ++num_of_child;\n        }\n        if\
    \ ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);\n\
    \    }\n    void solve(const vector<vector<int>> &G) {\n        int N = (int)G.size();\n\
    \        seen.assign(N, 0);\n        ord.resize(N);\n        low.resize(N);\n\
    \        aps.clear();\n        brs.clear();\n        for (int v = 0; v < N; ++v)\n\
    \            if (!seen[v]) dfs_lowlink(G, v);\n    }\n};\n"
  code: "struct LowLink {\n    // main results\n    vector<int> aps;             //\
    \ articulation points\n    vector<pair<int, int>> brs;  // brideges\n\n    //\
    \ intermediate results\n    vector<int> seen, ord, low;\n    void dfs_lowlink(const\
    \ vector<vector<int>> &G, int v, int p = -1) {\n        static int time = 0;\n\
    \        seen[v] = true;\n        ord[v] = low[v] = time++;\n        int num_of_child\
    \ = 0;\n        bool exist = false;  // for articulation point\n        for (auto\
    \ ch : G[v]) {\n            if (seen[ch]) {\n                if (ch != p) low[v]\
    \ = min(low[v], ord[ch]);  // back edge\n                continue;\n         \
    \   }\n            dfs_lowlink(G, ch, v);\n            low[v] = min(low[v], low[ch]);\
    \  // forward edge of DFS-tree\n            if (ord[v] < low[ch]) brs.emplace_back(v,\
    \ ch);\n            if (ord[v] <= low[ch]) exist = true;\n            ++num_of_child;\n\
    \        }\n        if ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);\n\
    \    }\n    void solve(const vector<vector<int>> &G) {\n        int N = (int)G.size();\n\
    \        seen.assign(N, 0);\n        ord.resize(N);\n        low.resize(N);\n\
    \        aps.clear();\n        brs.clear();\n        for (int v = 0; v < N; ++v)\n\
    \            if (!seen[v]) dfs_lowlink(G, v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/low-link.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_3_B.test.cpp
  - test/AOJ/GRL_3_A.test.cpp
documentation_of: graph/low-link.hpp
layout: document
title: "Low-Link(\u6A4B,\u95A2\u7BC0\u70B9\u5217\u6319)"
---

## 概要

アイディア: DFS をしたとき、DFS 後退辺は橋とはなりえない<br>

* $ord[v]$ := 頂点を訪れた順番<br>
* $low[v]$ := $v$から「DFS 木の根から葉へ進む」or「後退辺を葉から根へ進む」ことによって辿り着ける頂点の$ord$の最小値

DFS で $u$ -> ... -> $v$ と来て、$v$ から $u$ への後退辺があると、このサイクルの $low$ がすべて $ord[u]$ (以下) になる感じ

このことから、DFS-search で、辺 $v$ - $ch$ を $v$ -> $ch$ の順に探索したときに、
辺 $v$-$to$ が橋　⇔　$ord[v]$ < $low[ch]$

DFS-search で
頂点 $v$ が関節点　⇔
* $v$ が根のとき、$deg[v]$ > 1<br>
* それ以外のとき、$u$ のある子供 $ch$ が存在して、$ord[v]$ <= $low[ch]$