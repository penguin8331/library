---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal (\u6700\u5C0F\u5168\u57DF\u6728) $O(E log V)$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1160.test.cpp
    title: test/AOJ/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/union-find.hpp\"\n\nstruct UnionFind {\n    vector<int>\
    \ par;\n\n    UnionFind() {}\n    explicit UnionFind(int n) : par(n, -1) {}\n\
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct UnionFind {\n\
    \    vector<int> par;\n\n    UnionFind() {}\n    explicit UnionFind(int n) : par(n,\
    \ -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int x) {\n\
    \        if (par[x] < 0)\n            return x;\n        else\n            return\
    \ par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (par[x] >\
    \ par[y]) swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n      \
    \  return true;\n    }\n\n    int size(int x) {\n        return -par[root(x)];\n\
    \    }\n\n    vector<vector<int>> groups() {\n        map<int, vector<int>> root_buf;\n\
    \        for (int i = 0; i < (int)par.size(); ++i) {\n            int r = root(i);\n\
    \            root_buf[r].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (const auto& i : root_buf) {\n            res.push_back(i.second);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2023-04-21 23:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1160.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
  - test/AOJ/DSL_1_A.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
title: UnionFind
---
