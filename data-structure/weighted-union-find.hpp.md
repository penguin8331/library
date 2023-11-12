---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/weighted-union-find.hpp\"\ntemplate <class\
    \ T>\nstruct WeightedUnionFind {\n    // core member\n    vector<int> par;\n \
    \   vector<T> weight;\n\n    // constructor\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ N, T zero = 0) : par(N, -1), weight(N, zero) {}\n    void init(int N, T zero\
    \ = 0) {\n        par.assign(N, -1);\n        weight.assign(N, zero);\n    }\n\
    \n    // core methods\n    int root(int x) {\n        if (par[x] < 0)\n      \
    \      return x;\n        else {\n            int r = root(par[x]);\n        \
    \    weight[x] += weight[par[x]];\n            return par[x] = r;\n        }\n\
    \    }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -par[root(x)]; }\n\n    // v[y] - v[x] = w\n    bool merge(int x,\
    \ int y, T w) {\n        w += get_weight(x), w -= get_weight(y);\n        x =\
    \ root(x), y = root(y);\n        if (x == y) return false;\n        if (par[x]\
    \ > par[y]) swap(x, y), w = -w;  // merge technique\n        par[x] += par[y];\n\
    \        par[y] = x;\n        weight[y] = w;\n        return true;\n    }\n\n\
    \    // get v[x]\n    T get_weight(int x) {\n        root(x);\n        return\
    \ weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x, int y) {\
    \ return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};\n"
  code: "template <class T>\nstruct WeightedUnionFind {\n    // core member\n    vector<int>\
    \ par;\n    vector<T> weight;\n\n    // constructor\n    WeightedUnionFind() {}\n\
    \    WeightedUnionFind(int N, T zero = 0) : par(N, -1), weight(N, zero) {}\n \
    \   void init(int N, T zero = 0) {\n        par.assign(N, -1);\n        weight.assign(N,\
    \ zero);\n    }\n\n    // core methods\n    int root(int x) {\n        if (par[x]\
    \ < 0)\n            return x;\n        else {\n            int r = root(par[x]);\n\
    \            weight[x] += weight[par[x]];\n            return par[x] = r;\n  \
    \      }\n    }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int size(int x) { return -par[root(x)]; }\n\n    // v[y] - v[x] = w\n   \
    \ bool merge(int x, int y, T w) {\n        w += get_weight(x), w -= get_weight(y);\n\
    \        x = root(x), y = root(y);\n        if (x == y) return false;\n      \
    \  if (par[x] > par[y]) swap(x, y), w = -w;  // merge technique\n        par[x]\
    \ += par[y];\n        par[y] = x;\n        weight[y] = w;\n        return true;\n\
    \    }\n\n    // get v[x]\n    T get_weight(int x) {\n        root(x);\n     \
    \   return weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x,\
    \ int y) { return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/weighted-union-find.hpp
  requiredBy: []
  timestamp: '2023-11-12 18:33:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/weighted-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/weighted-union-find.hpp
- /library/data-structure/weighted-union-find.hpp.html
title: data-structure/weighted-union-find.hpp
---
