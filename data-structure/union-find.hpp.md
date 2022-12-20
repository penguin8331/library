---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1160.test.cpp
    title: test/AOJ/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind {\n  \
    \  vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int n) : par(n, -1) {}\n\
    \    void init(int n) { par.assign(n, -1); }\n\n    int root(int x) {\n      \
    \  if (par[x] < 0)\n            return x;\n        else\n            return par[x]\
    \ = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n        return root(x)\
    \ == root(y);\n    }\n\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (par[x] >\
    \ par[y]) swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n      \
    \  return true;\n    }\n\n    int size(int x) {\n        return -par[root(x)];\n\
    \    }\n\n    vector<vector<int>> groups() {\n        map<int, vector<int>> root_buf;\n\
    \        for (int i = 0; i < (int)par.size(); ++i) {\n            int r = root(i);\n\
    \            root_buf[r].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (const auto& i : root_buf) {\n            res.push_back(i.second);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "struct UnionFind {\n    vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int\
    \ n) : par(n, -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int\
    \ x) {\n        if (par[x] < 0)\n            return x;\n        else\n       \
    \     return par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n\
    \        return root(x) == root(y);\n    }\n\n    bool unite(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x == y) return false;\n\
    \        if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\n       \
    \ par[y] = x;\n        return true;\n    }\n\n    int size(int x) {\n        return\
    \ -par[root(x)];\n    }\n\n    vector<vector<int>> groups() {\n        map<int,\
    \ vector<int>> root_buf;\n        for (int i = 0; i < (int)par.size(); ++i) {\n\
    \            int r = root(i);\n            root_buf[r].push_back(i);\n       \
    \ }\n        vector<vector<int>> res;\n        for (const auto& i : root_buf)\
    \ {\n            res.push_back(i.second);\n        }\n        return res;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1160.test.cpp
  - test/AOJ/DSL_1_A.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
redirect_from:
- /library/data-structure/union-find.hpp
- /library/data-structure/union-find.hpp.html
title: data-structure/union-find.hpp
---