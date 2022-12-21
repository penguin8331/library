---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
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
    \        }\n        return res;\n    }\n};\n#line 2 \"graph/kruskal.hpp\"\n\n\
    struct Edge {\n    long long u;\n    long long v;\n    long long cost;\n};\nbool\
    \ comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }  // \u8FBA\
    \u3092\u76F4\u63A5\u6BD4\u8F03\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\nstruct\
    \ Kruskal {\n    UnionFind uft;\n    long long sum;  // \u6700\u5C0F\u5168\u57DF\
    \u6728\u306E\u91CD\u307F\u306E\u7DCF\u548C\n    vector<Edge> edges;\n    int V;\n\
    \    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init();\
    \ }\n    void init() {\n        sort(edges.begin(), edges.end(), comp_e);  //\
    \ \u8FBA\u306E\u91CD\u307F\u3067\u30BD\u30FC\u30C8\n        uft = UnionFind(V);\n\
    \        sum = 0;\n        for (auto e : edges) {\n            if (!uft.issame(e.u,\
    \ e.v)) {  // \u9589\u8DEF\u306B\u306A\u3089\u306A\u3051\u308C\u3070\u52A0\u3048\
    \u308B\n                uft.unite(e.u, e.v);\n                sum += e.cost;\n\
    \            }\n        }\n    }\n};\n"
  code: "#include \"data-structure/union-find.hpp\"\n\nstruct Edge {\n    long long\
    \ u;\n    long long v;\n    long long cost;\n};\nbool comp_e(const Edge &e1, const\
    \ Edge &e2) { return e1.cost < e2.cost; }  // \u8FBA\u3092\u76F4\u63A5\u6BD4\u8F03\
    \u3059\u308B\u305F\u3081\u306E\u95A2\u6570\nstruct Kruskal {\n    UnionFind uft;\n\
    \    long long sum;  // \u6700\u5C0F\u5168\u57DF\u6728\u306E\u91CD\u307F\u306E\
    \u7DCF\u548C\n    vector<Edge> edges;\n    int V;\n    Kruskal(const vector<Edge>\
    \ &edges_, int V_) : edges(edges_), V(V_) { init(); }\n    void init() {\n   \
    \     sort(edges.begin(), edges.end(), comp_e);  // \u8FBA\u306E\u91CD\u307F\u3067\
    \u30BD\u30FC\u30C8\n        uft = UnionFind(V);\n        sum = 0;\n        for\
    \ (auto e : edges) {\n            if (!uft.issame(e.u, e.v)) {  // \u9589\u8DEF\
    \u306B\u306A\u3089\u306A\u3051\u308C\u3070\u52A0\u3048\u308B\n               \
    \ uft.unite(e.u, e.v);\n                sum += e.cost;\n            }\n      \
    \  }\n    }\n};"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-12-21 22:31:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
