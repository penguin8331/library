---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n//\n// Union-Find tree\n\
    //\n\n/*\n    \u30FB\u4F75\u5408\u6642\u306E\u5DE5\u592B: union by size\n    par[x]:\
    \ x \u304C\u6839\u306E\u3068\u304D\u306F x \u3092\u542B\u3080\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA (\u306E -1 \u500D)\u3001\u305D\u3046\u3067\u306A\
    \u3044\u3068\u304D\u306F\u89AA\u30CE\u30FC\u30C9\n\n    issame(x, y): x \u3068\
    \ y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3044\u308B\u304B, \u8A08\
    \u7B97\u91CF\u306F\u306A\u3089\u3057 O(\u03B1(n))\n    unite(x, y): x \u3068 y\
    \ \u3092\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B, \u8A08\u7B97\u91CF\
    \u306F\u306A\u3089\u3057 O(\u03B1(n))\n    size(x): x \u3092\u542B\u3080\u30B0\
    \u30EB\u30FC\u30D7\u306E\u6240\u5C5E\u30E1\u30F3\u30D0\u30FC\u6570\n*/\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#pragma region UnionFind\nstruct UnionFind\
    \ {\n    vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int n) : par(n,\
    \ -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int x) {\n\
    \        if (par[x] < 0)\n            return x;\n        else\n            return\
    \ par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (par[x] >\
    \ par[y]) swap(x, y);  // merge technique\n        par[x] += par[y];\n       \
    \ par[y] = x;\n        return true;\n    }\n\n    int size(int x) {\n        return\
    \ -par[root(x)];\n    }\n\n    vector<vector<int>> groups() {\n        map<int,\
    \ vector<int>> root_buf;\n        for (int i = 0; i < par.size(); ++i) {\n   \
    \         int r = root(i);\n            root_buf[r].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (const auto& i : root_buf) {\n\
    \            res.push_back(i.second);\n        }\n        return res;\n    }\n\
    };\n#pragma endregion UnionFind\n"
  code: "//\n// Union-Find tree\n//\n\n/*\n    \u30FB\u4F75\u5408\u6642\u306E\u5DE5\
    \u592B: union by size\n    par[x]: x \u304C\u6839\u306E\u3068\u304D\u306F x \u3092\
    \u542B\u3080\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA (\u306E -1 \u500D\
    )\u3001\u305D\u3046\u3067\u306A\u3044\u3068\u304D\u306F\u89AA\u30CE\u30FC\u30C9\
    \n\n    issame(x, y): x \u3068 y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\
    \u3044\u308B\u304B, \u8A08\u7B97\u91CF\u306F\u306A\u3089\u3057 O(\u03B1(n))\n\
    \    unite(x, y): x \u3068 y \u3092\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3059\
    \u308B, \u8A08\u7B97\u91CF\u306F\u306A\u3089\u3057 O(\u03B1(n))\n    size(x):\
    \ x \u3092\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u306E\u6240\u5C5E\u30E1\u30F3\u30D0\
    \u30FC\u6570\n*/\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#pragma\
    \ region UnionFind\nstruct UnionFind {\n    vector<int> par;\n\n    UnionFind()\
    \ {}\n    UnionFind(int n) : par(n, -1) {}\n    void init(int n) { par.assign(n,\
    \ -1); }\n\n    int root(int x) {\n        if (par[x] < 0)\n            return\
    \ x;\n        else\n            return par[x] = root(par[x]);\n    }\n\n    bool\
    \ issame(int x, int y) {\n        return root(x) == root(y);\n    }\n\n    bool\
    \ merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n        if\
    \ (x == y) return false;\n        if (par[x] > par[y]) swap(x, y);  // merge technique\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \n    int size(int x) {\n        return -par[root(x)];\n    }\n\n    vector<vector<int>>\
    \ groups() {\n        map<int, vector<int>> root_buf;\n        for (int i = 0;\
    \ i < par.size(); ++i) {\n            int r = root(i);\n            root_buf[r].push_back(i);\n\
    \        }\n        vector<vector<int>> res;\n        for (const auto& i : root_buf)\
    \ {\n            res.push_back(i.second);\n        }\n        return res;\n  \
    \  }\n};\n#pragma endregion UnionFind\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2022-12-19 20:44:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
