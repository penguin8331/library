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
