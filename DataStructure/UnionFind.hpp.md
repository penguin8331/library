---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/DSL_1_A.cpp
    title: test/AOJ/DSL_1_A.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.hpp\"\nstruct UnionFind {\n    vector<int>\
    \ par;\n\n    UnionFind() {}\n    UnionFind(int n) : par(n, -1) {}\n    void init(int\
    \ n) { par.assign(n, -1); }\n\n    int root(int x) {\n        if (par[x] < 0)\n\
    \            return x;\n        else\n            return par[x] = root(par[x]);\n\
    \    }\n\n    bool issame(int x, int y) {\n        return root(x) == root(y);\n\
    \    }\n\n    bool unite(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (par[x] > par[y]) swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \n    int size(int x) {\n        return -par[root(x)];\n    }\n\n    vector<vector<int>>\
    \ groups() {\n        map<int, vector<int>> root_buf;\n        for (int i = 0;\
    \ i < (int)par.size(); ++i) {\n            int r = root(i);\n            root_buf[r].push_back(i);\n\
    \        }\n        vector<vector<int>> res;\n        for (const auto& i : root_buf)\
    \ {\n            res.push_back(i.second);\n        }\n        return res;\n  \
    \  }\n};\n"
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
  path: DataStructure/UnionFind.hpp
  requiredBy:
  - test/AOJ/DSL_1_A.cpp
  timestamp: '2022-12-19 21:17:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.hpp
- /library/DataStructure/UnionFind.hpp.html
title: DataStructure/UnionFind.hpp
---
